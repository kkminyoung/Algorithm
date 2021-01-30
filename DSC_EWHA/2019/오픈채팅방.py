def solution(record):
    answer = []
    id_dict = {}
    printer = {'Enter':'님이 들어왔습니다.', 'Leave':'님이 나갔습니다.'}
    for r in record:
        rr = r.split(' ')
        if rr[0] in ['Enter', 'Change']:
            id_dict[rr[1]] = rr[2]

    for r in record:
        if r.split(' ')[0] in ['Enter', 'Leave']:
            answer.append(id_dict[r.split(' ')[1]] + printer[r.split(' ')[0]])

    return answer
