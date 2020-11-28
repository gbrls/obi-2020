import os, subprocess

from os import listdir
from os.path import isfile, join, isdir

def test(exe, pref, n):
    os.system('./{} < {}/{}.in > {}/{}.out'.format(exe,pref,n,pref,n))
    ans = 'err'
    try:
        ans = subprocess.check_output(['diff', '{}/{}.out'.format(pref, n),
            '{}/{}.sol'.format(pref,n)],
            timeout=1)
    except:
        pass


    os.system('rm {}/{}.out'.format(pref,n))
    ans = len(ans)

    return ans == 0

def nfiles(path):
    onlyfiles = [f for f in listdir(path) if isfile(join(path, f))]
    return len(onlyfiles)

def ndir(path):
    dirs = [f for f in listdir(path) if isdir(join(path, f))]
    return len(dirs)


def testAll(path, exe):
    dirs = ndir(path)
    for dir in range(1,dirs+1):
        n = nfiles('./{}/{}'.format(path, dir))//2
        str = ''
        for i in range(1, n+1):
            a = test('{}'.format(exe), '{}/{}'.format(path, dir), i)
            if a == True:
                str += '.'
            else:
                str += 'x'
        print(str)

def compile(file):
    os.system('g++ {}.cpp -o {}'.format(file,file))

path = input('Digite a pasta com os testes: ')
exe = input('digite o arquivo fonte: ')

compile(exe)
testAll(path,exe)

#test('a', 'A/1', '1')
#print(nfiles('./A/5'));
