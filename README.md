# Linuxcnc_Kinematics

SA-CNC-CLUB
Rudy du Preez


**halcompile - Build, compile and install LinuxCNC HAL components**


SYNOPSIS
            halcompile   [--compile|--preprocess|--document|--view-doc]  comp‐
            file...
       sudo halcompile [--install|--install-doc] compfile...
            halcompile --compile --userspace cfile...
       sudo halcompile --install --userspace cfile...
       sudo halcompile --install --userspace pyfile...




How to make compile .comp file into .so

```
halcompile --compile <filename.comp>
halcompile --compile ddt.comp

```

OutPut is 

```
cnc@debian:~/Desktop/linuxcnc_comp/c$ halcompile --compile ddt.comp
Compiling realtime ddt.c
Linking ddt.so

```



How to make compile .comp file into .c



```
halcompile --preprocess <filename.comp>

halcompile --preprocess ddt.comp

halcompile --userspace ddt.comp
```



python file comp 

halcompile --install --userspace arduino-connector.py





STUDY


```
-------BEST
https://github.com/hieplchan/orocos_linuxcnc_component

https://github.com/OpenSourceDevelop/canfd.comp


https://github.com/travis-farmer/linuxcnc


https://github.com/hieplchan/orocos_linuxcnc_component_python/tree/master
--------
```




LINUXCNC_ ETHERNET
```

https://github.com/travis-farmer/lcnc_mqtt_status_lights/blob/main/lcnc_mqtt_status_lights.ino

```






https://github.com/cnc-club/linuxcnc-engraving-comp
https://www.hase.net/CNC/CNC/PCB_milling.html


https://github.com/tinkercnc/testdriver

https://github.com/zarfld/LinuxCnc_PokeysLibComp

https://github.com/mydani/linuxcnc_misc

https://github.com/peter-doronin/linuxcnc-comp


https://github.com/andypugh/HalComps

https://github.com/OpenSourceDevelop/max31865.comp


https://github.com/hieplchan/orocos_linuxcnc_component
https://github.com/MrNinefinger/EMCO-Compact5-Lathe-CNC-config




Tools
https://github.com/mattvenn/cad/tree/master/tools



http://phk.freebsd.dk/CncPcb/index.html

https://www.hase.net/CNC/CNC/PCB_milling.html

https://cnc-club.ru/forum/viewtopic.php?f=15&t=3124&p=72441#p72441

https://github.com/cnc-club/linuxcnc-features

https://github.com/hase-berlin/pcbGcodeZprobing





VID

https://www.youtube.com/watch?v=zpx6dOgNJHA&ab_channel=GMSystem2001








Advance Settings


https://forum.linuxcnc.org/38-general-linuxcnc-questions/50246-2-9-part-display-axis#282166
https://forum.linuxcnc.org/qtpyvcp/51447-probe-basic-4th-axis-plot?start=0



SIM
https://forum.linuxcnc.org/10-advanced-configuration/38457-mitsubishi-rv-6sdl-switchkins-config-with-simulation#158467


