# PacMan-Clone
#####A clone of the well known game for a group assignment

[![Build Status](https://travis-ci.org/lupus590/Uni-PacMan-Clone.svg?branch=master)](https://travis-ci.org/lupus590/Uni-PacMan-Clone)

######Do you guys want a Qt code style xml? that way all of our code will have the same layout

Please try to keep the master branch with working code. If you want to test something, use your dev branch. **It is your responsibility to keep your branch up to date with the master.**

One final rule: you break it, you ~~buy~~ debug it, hope you know GDB! :trollface:

We are using travis as our contious intergation server, it will (attempt to) build every branch in this repo. View the CI builds here: https://travis-ci.org/lupus590/Uni-PacMan-Clone/builds

Until I can setup visual studio to do the debugging we will have to use this: http://darkdust.net/files/GDB%20Cheat%20Sheet.pdf

If you want/need to debug then use GDB (see above link) or use QT creator for a gui: https://www.qt.io/download/

####Team Details

Student Name|Github user Name|Commit Email
------------|----------------|------------
Axl|AxlWest|AxlWest@users.noreply.github.com
Ieuan|Flowerpot94|Flowerpot94@users.noreply.github.com
James|Cook-E|Cook-E@users.noreply.github.com 
Nephi|lupus590|lupus590@users.noreply.github.com


####Setting up visual studio and windows to work with make files and g++

There is a Qt Creator project now too, I would recoment that you use that https://www.qt.io/download/

If you are using Qt Creator, I would recommend the todo plugin: in Qt Creator click help->about plugins...->in the utilities sub tree->Todo. Feel free to see what it does by selecting it (so it's highlighted, not just ticked) and click details.

#####If you really want to use VS though: (not recommended as debugging will be difficult)

Install: http://nuwen.net/mingw.html

Add the bin folder created from above to the windows environment path: http://www.computerhope.com/issues/ch000549.htm

Windows and visual studio are now ready with the project I have provided

-Nephi

####Random Stuff

this may be useful: http://www.planetgeek.ch/wp-content/uploads/2013/06/Clean-Code-V2.1.pdf
