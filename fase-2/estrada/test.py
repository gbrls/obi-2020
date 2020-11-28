import os, subprocess

from os import listdir
from os.path import isfile, join


def test(exe, pref, n):
    os.system('./{} < {}/{}.in > {}/{}.out'.format(exe,pref,n,pref,n))
    ans = 'err'
    try:
        ans = subprocess.check_output(['diff', '{}/{}.out'.format(pref, n),
            '{}/{}.sol'.format(pref,n)])
    except:
        pass


    os.system('rm {}/{}.out'.format(pref,n))
    ans = len(ans)

    return ans == 0

def nfiles(path):
    onlyfiles = [f for f in listdir(path) if isfile(join(path, f))]
    return len(onlyfiles)

for dir in [1,2,3,4,5,6,7,8,9]:
    n = nfiles('./A/{}'.format(dir))//2
    str = ''
    for i in range(1, n+1):
        a = test('b', 'A/{}'.format(dir), i)
        if a == True:
            str += '.'
        else:
            str += 'x'
    print(str)

#test('a', 'A/1', '1')
#print(nfiles('./A/5'));
