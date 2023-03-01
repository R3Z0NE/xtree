# Xtree
Simple program printing out xmas tree to the console.<br>
Written in C, for training purposes, and for learning how to use GitHub.<br>

# Usage
User can provide two CLI arguments:<br>
First one has to be character of which the tree will be made of. Some special characters will need "escaping", if that is the case read the "Limitations" section<br>
Second argument has to be width of the tree. The value has to be integer from range 1-200. If you need more that that, read the "Limitations" section<br>
If no arguments are specified, the program defaults the character to 'x' and the width to 21<br>

Example usages:<br>
"./xtree ^ 50"<br>
"./xtree '&' 30"<br>
"./xtree %"

# Limitations
The character provided by the user can be really anything, just with a few exceptions defined by shell you are working in. For example you can't provide "raw" asterisk if running this program from powershell because this environment treats this character specially (other shells possibly too). You have to "escape" this character first - you can do this like this: "./xtree.exe \* 20". In this example we used backslash to escape the asterisk, please note that different shells can have different escape characters. Additionally program takes only first character from user input so if you will "./xtree HAHA", the tree will still be only made from 'H' character.<br><br>
One more limitation is width of the tree. I set it to be at most 200, and at least 1 character wide. If for some reason you need tree wider that that, you can remove "width > 200" from this one big 'if' statement, or use a special CLI flag that will be implemented in near future. For now user can't specify the width of a tree without additionally specyfying the character first.

# TODO
If some flag is specified, the program will take full input, so single tree character could be made of two, or more characters. Additionally the flag will turn off the maximum width limitation of 200.<br><br>
User can provide only width of the tree, leaving the character variable at default.
