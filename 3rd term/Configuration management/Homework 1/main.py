import zipfile
'''ls, cd, cat'''

def pwd(cur_dir):
    print(cur_dir)

def ls(file, cur_dir):
    file_zip=zipfile.ZipFile(file, 'r')
    path=zipfile.Path(file_zip, at=cur_dir)
    for paths in path.iterdir():
        print(str(paths)[len(file)+3+len(cur_dir)-2:])

def cd(cur_dir,command, min_len):
    command=command[3:]
    if command=="..":
        cur_dir=cur_dir[:-1]
        while (len(cur_dir)>min_len and cur_dir[len(cur_dir)-1]!='/'):
            cur_dir = cur_dir[:-1]
        if len(cur_dir)>=min_len:
            return cur_dir
        else:
            return cur_dir+'/'

    elif cur_dir in command:
        return command+'/'

    else:
        return cur_dir+command+'/'

def cat(command, cur_dir,file):
    command=command[4:]
    file_zip = zipfile.ZipFile(file, 'r')
    path = zipfile.Path(file_zip, at=cur_dir+command)
    print(path.read_text())

def main():
    print ("Введите название архива:")
    file=input()
    min_len=len(file[:-4]+'/')
    cur_dir=file[:-4]+'/'

    while True:
        print(cur_dir)
        command=input()

        if command=="pwd":
            pwd(cur_dir)

        if command=="ls":
            ls(file, cur_dir)

        if command[0]=="c" and command[1]=="d":
            cur_dir=cd(cur_dir,command, min_len)

        if command[0]=="c" and command[1]=="a" and command[2]=="t":
            cat(command, cur_dir, file)

if __name__=="__main__":
    main()