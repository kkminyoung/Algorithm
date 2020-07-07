#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

struct MEMORY {
	int page_num;
	int reference_bit;
	int dirty_bit;
};

struct PAGE {
	int memory_location;
	int valid_bit;
};

struct PAGE page[200000];

int main(int argc, char *argv[]) {
	int memory_size = atoi(argv[1]);

	int i;
	int p_num;
	int w;
	int clock = 0;
	int out_pg = 0;
	int page_fault = 0;
	int w_num = 0;
	int head_movement = 0;
	int l_current = 0;
	int l_before = 0;
	int l_after = 0;

	FILE *input_file = fopen("a.txt", "r");
	struct MEMORY *memory = (struct MEMORY*)malloc(memory_size * sizeof(struct MEMORY));

	if (input_file == NULL) {
		printf("Could not read files.\n");
		return -1;
	}

	for (int i = 0; i < memory_size; i++) {
		memory[i].reference_bit = 0;
		memory[i].dirty_bit = 0;
	}

	for (int i = 0; i < 200000; i++)
		page[i].valid_bit = 0;

	while (!feof(input_file)) {
		fscanf(input_file, "%d %d", &p_num, &w);
		if (page[p_num].valid_bit == 1) {
			memory[page[p_num].memory_location].reference_bit = 1;
			if (w == 1)
				memory[page[p_num].memory_location].dirty_bit = 1;
		}
		else {
			page_fault++;

			if (page_fault <= memory_size) {
				l_after = p_num / 1000;
				if (l_after > l_before)
					head_movement += (l_after - l_before);
				else
					head_movement += (l_before - l_after);

				l_before = l_after;
				memory[clock].page_num = p_num;
				memory[clock].dirty_bit = w;
				page[p_num].memory_location = clock;
				page[p_num].valid_bit = 1;
				clock++;
				if (clock == memory_size)
					clock = 0;
			}

			else if (page_fault > memory_size) {

				while (memory[clock].reference_bit == 1) {
					memory[clock].reference_bit = 0;
					clock++;
					if (clock == memory_size)
						clock = 0;
				}

				page[memory[clock].page_num].valid_bit = 0;
				if (memory[clock].dirty_bit == 1) {
					w_num = w_num + 1;
					memory[clock].dirty_bit = w;
					l_current = memory[clock].page_num / 1000;
					l_after = p_num / 1000;

					if (l_current > l_before)
						head_movement += (l_current - l_before);
					else
						head_movement += (l_before - l_current);

					if (l_after > l_current)
						head_movement += (l_after - l_current);
					else
						head_movement += (l_current - l_after);

					l_before = l_after;
				}

				else {
					l_current = memory[clock].page_num / 1000;
					l_after = p_num / 1000;

					if (l_after > l_before)
						head_movement += (l_after - l_before);
					else
						head_movement += (l_before - l_after);
					l_before = l_after;
					memory[clock].dirty_bit = w;
				}

				memory[clock].page_num = p_num;
				page[p_num].memory_location = clock;
				page[p_num].valid_bit = 1;
				clock++;
				if (clock == memory_size)
					clock = 0;
			}
		}
	}
	fclose(input_file);
	free(memory);

	printf("%d\n", page_fault);
	printf("%d\n", w_num);
	printf("%d\n", head_movement);

	return 0;
}
