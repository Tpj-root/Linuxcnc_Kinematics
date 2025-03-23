# Linuxcnc_Kinematics

SA-CNC-CLUB
Rudy du Preez


**FindTheSite**

```
https://sa-cnc.com/?page_id=5375
https://web.archive.org/web/20240223111327/https://sa-cnc.com/?page_id=5375
```



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





https://github.com/cnc-club
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
```
https://www.youtube.com/watch?v=zpx6dOgNJHA&ab_channel=GMSystem2001
https://www.youtube.com/watch?v=60jX20xwoZQ
https://www.youtube.com/watch?v=YwJLJxoKuM8&ab_channel=MakersEase
https://www.youtube.com/watch?v=rZoLP0v50rw
https://www.youtube.com/watch?v=qiCD0MxI1_I&ab_channel=FerySetyawan
```




https://link.springer.com/article/10.1007/s13369-022-06794-6


DESIGn
https://www.cadcrowd.com/3d-models/6-dof-robot



Advance Settings


https://forum.linuxcnc.org/38-general-linuxcnc-questions/50246-2-9-part-display-axis#282166
https://forum.linuxcnc.org/qtpyvcp/51447-probe-basic-4th-axis-plot?start=0



SIM
https://forum.linuxcnc.org/10-advanced-configuration/38457-mitsubishi-rv-6sdl-switchkins-config-with-simulation#158467








STUDY_KIN

```
http://alvarestech.com/temp/RoboAseaIRB6S2-Fiat/CinematicaExemplosManuaisConfigurador-DH-EMC/
https://newscrewdriver.com/2022/12/28/successful-linuxcnc-stepper-motor-test/
```






L_CNC
https://forum.linuxcnc.org/38-general-linuxcnc-questions/30764-how-do-i-setup-a-5-axis-mill




```
https://cnc-sa.co.za/cnc-machines-south-africa
https://iessa.co.za/cnc-repairs
https://www.cnc.co.za/
https://www.cnc-academy.com/
https://cnc-club.ru/forum/index.php
```



Wiki

```
http://wiki.linuxcnc.org/cgi-bin/wiki.pl?ModIO

```