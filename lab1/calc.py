with open('time_res.txt', 'r') as f:
    lines = f.readlines()
    avg_coef_standard = 0
    avg_coef_hand_made = 0
    for line in lines:
        naive, standard, hand_made = map(float, line.split())
        avg_coef_standard += naive / standard
        avg_coef_hand_made += naive / hand_made
    print(avg_coef_standard / len(lines), avg_coef_hand_made / len(lines))
