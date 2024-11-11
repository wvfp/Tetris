#递归将本文件夹下所有.c和.h放到WIDGETS中
file(GLOB_RECURSE GAMEWIDGET ./GameWidget/  *.c *.h)
file(GLOB_RECURSE HELPWIDGET ./HelpeWidget/  *.c *.h)
file(GLOB_RECURSE MENUWIDGET ./MenupWidget/  *.c *.h)
file(GLOB_RECURSE PAUSEWIDGET ./PauseWidget/  *.c *.h)
file(GLOB_RECURSE SETTINGWIDGET ./SetingWidget/  *.c *.h)
#将Application中所有cpp编译为widgets这个lib库
add_library(widgets ${MENUWIDGET} ${GAMEWIDGET} ${HELPSTRING} ${PAUSEWIDGET} ${SETTINGWIDGET})