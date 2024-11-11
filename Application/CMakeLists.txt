#递归将本文件夹下所有cpp放到FUNCS中
file(GLOB_RECURSE APP ./  *.c *.h)

#将Application中所有cpp编译为app这个lib库
add_library(app ${APP})