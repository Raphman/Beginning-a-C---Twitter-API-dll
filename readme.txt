Okay so here is my little twitter rest API dll! All this does is ask for a username, and gets the person's last tweet.
if the name does not exist, or the person has privacy settings enabled, it will error out and tell the user what happened.
so in the RestWeb function is where all the magic happens.
You can see in twitterAPI.h, it's  very bare, just one function call. the static as you all know means that the function can be called without instantiating the class.
the _delSpec(dllexport) means that it is a function in the dll that's going to be used by an external program.
all thouse includes are for various things they are necessary. in the mian function, you'll see that I have a ton of using statements. 
Those are to  beable to use the systemcalls, and the .net calls, as well as some XML parsing functionality.
It kinda makes things like c#.

	Okay so basically, the function asks for a user's name, then converts it to a System String for .net usage.
after that it appends it to the uri, which is the twitter rest call.
then we have our try statement

at the beginning you see I do an HTTPrequest, that basically makes the api call to twitter with the information ( checkout twitter's Rest APi Page)
you have to set the method to get, because we're pulling. if you were posting, it would be 'POST'.
then comes the response, which as you can tell, gets the response to the request in XML format.

then we grab the stream out of the response, and the string from that, and we push it into another System String

Then a XML reader is created,  and is used to parse through the text. 
if it hits a "Text" field, which is a tweet, it appends it to the result. then if it hits a name, it does the same thing
it writes the result to the screen, then it closes the stream and request and it's done! 

However, you can fail the call, if the username you entered does not exist, or if the user has high privacy settings. That's where the catch comes in.

basically, if the try fails for any reason, it'll  print out a generic error message, rather than crashing out. So there you have it!

Also just so you guys know, this was for a school project, and it may not be updated very often, but I might just keep at it, since it was a pretty fun project, and a good skill to have!

I hope this helps somebody!

		-Raph