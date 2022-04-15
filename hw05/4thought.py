mp = {}
ops = [' ', ' ', ' ']

def init(i = 0):
    if i == 3:
        formula = '4' + '4'.join(ops) + '4'
        cal = formula.replace('/', '//')
        mp[eval(cal)] = (' '.join(formula))
        return
    
    for c in "+-*/":
        ops[i] = c
        init(i + 1)

if __name__ == '__main__':
    init()
    n = int(input())
    for _ in range(n):
        x = int(input())
        print(f"{ mp[x] } = { x }" if mp.get(x) != None else "no solution")