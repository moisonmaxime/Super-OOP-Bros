# Deliverable No. 1 - Proposal

link on ShareLaTeX - https://www.sharelatex.com/6257649535zzgfynvtmfcy

# Deliverable No. 2.2 - Final Report

link on ShareLaTeX - https://www.sharelatex.com/9672273773cfqftryvycgd

# Implimentation improvement(s)/change(s):

- In game.hpp I added a speed (float). Pass this speed into the function that draws the hitboxes (green tubes still not implimented). This is how much to move the tubes to the left of the screen. (x -= speed). By default this will move the tubes a little bit faster than the background. That is not an accident. This is important for the paralax affect. 

- (IMPORTANT): The texRect constructor does NOT take in floats for the constructor anymore. It takes in float POINTERS. This improves performance a little bit, because the hitboxes are constantly changing, so rather than send in the cordinants to the texture, we can simply print the texture using the pointer to the hitboxes. Much simpler and less resource intensive this way.

# Todo:

- Clean up code and make neater (remove unneeded things)
- Maybe some audio?

FREEGLUTAPP
-----------

This is a demo project to start implementing OpenGL applications
using freeglut. 

Linux:
 - Type make to compile the application
 - The makefile will compile all .cpp files in the folder
 - Edit the makefile to change the name of the executable

Windows:
 - Visual Studio 2015 is required 
 - Simply open the solution (glutapp.sln) in visualc15
 
macOS:
 - Use the glutapp.xcodeproj file to open the project in XCode
 - It has been tested with XCode 8 on macOS Sierra 10.12


Notes:
 - The provided freeglut library is only used in Windows; 
   in Linux and OS X the compiler will seek for the header
   files and libraries in the default development folders.
   
 - On macOS, you can compile in the command line, so you don't
   have to use XCode. Simply follow the Linux instructions. 
   XCode should still be installed so that you have the OpenGL
   and GLUT libraries. To get started with XCode, download it
   from the App Store. Open it and let it set itself up. Then
   in the terminal type: xcode-select -install
   This will install the command line compiler tools on your Mac
