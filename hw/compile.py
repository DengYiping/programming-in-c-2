import os
import sys

def entry():
    if len(sys.argv) <= 1:
        print("please specify the directory to compile")
        return -1

    dic_name = sys.argv[1]
    if dic_name == 'clean':
        dic_name = sys.argv[2]
        if dic_name[-1] != '/':
            dic_name = dic_name + '/'
        exe_list = []
        with open(dic_name + 'executable.list', 'r') as exe_list_f:
            exe_list = exe_list_f.readlines()
        exe_list = map(lambda x: x[:-1], exe_list)
        for exe in exe_list:
            os.remove(exe)
            print("remove %s" % exe)
        os.remove(dic_name + 'executable.list')
        return 0

    if dic_name[-1] != '/':
        dic_name = dic_name + '/'
    files = os.listdir(dic_name)
    targets = []
    for f_name in files:
        if len(f_name) > 2 and f_name[-2:] == '.c':
            source = dic_name + f_name
            target = dic_name + f_name[:-2]

            cmd_compile = 'gcc -Wall -o {} {}'.format(target, source)
            os.system(cmd_compile)

            if os.path.isfile(target):
                print("{} successfully compiled to {}".format(source, target))
                targets.append(target)
            else:
                print("error on compiling {}".format(source))
    with open(dic_name + 'executable.list','w') as target_file:
        for target in targets:
            target_file.write(target + '\n')


if __name__ == '__main__':
    entry()
