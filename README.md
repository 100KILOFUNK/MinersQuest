# MinersQuest


# ON LINUX
You Need to isntall sfml, see their documentation
use the compile.sh to compile the program. it takes one argument and that is the name of the runnable file. the flag '-r' also runs the software after compiling



# Principles on saving

The game class should handle saving and loading.
the save file should look something like this;

Player			//keyword when loading
3			//nr of lives
2			//how many levels done
sword			//equipped weapon when saved.
Inventory		//keyword when loading
itemA			//which items the player has
itemB			//maximum amount is 16
itemC
itemD



#Level loading

the level files, which define the levels (duh) consists of 5 parts.

part0 x			//x is where the part begins
collidable x,y		//collidable is an object the player can interact with
collidable x,y
collidable x,y
part1 x
collidable x,y
collidable x,y 
collidable x,y
collidable x,y
part2 x
etc
etc


the reason we devide the levels into differents parts, its because we can optimize the collision in a much smoother way. 
By just checking the collidables of each part we dont have to check all the objects like we do today (2016/06/12)
after the player has chosen the level, the game class will be responsible of loading the level. 
