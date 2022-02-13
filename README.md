local and environment variable: $[variable name]
      	     replace the variable name call by it's variable value.
      	     take as variable name all alphanumeric charachter from $ to the first non alphanumeric character.
      	     a local variable
      error:
	    if an error occured don't execute the command line;
	    if the variable first char is not alphanumeric, exemple:
	       prompt> echo $&
	       Illegal variable name.
	    if the variable is not defined:
	       prompt> echo $aze
	       aze: Undefined variable.

redirection: [fd](<|<<|>|>>) [File name]
	     you know how it works if you are enot retarded.
	     error:
		   no file name:
		      Missing name for redirect.
		   Too much in or out redirection:
		       Ambigous (output/input) redirection.

pipe: [command] | [command]
      error:
	    if a command is missing, don't execute the command line and print:
	       Invalid null command.

separator: [command] (; && ||) [command]
	   ; (semicolons) separates differents commands, no error is associated with them.
	   
	   && (AND) opperand only run the 2nd command if the first one has succeed (return value == 0).
	      exemple:
			grep && ls: here ls is not executed because grep has failed.
			ls && grep: here grep is executed because ls has succeed.
	
	   || (OR) opperand only run the 2nb command if the first one has failed (return value != 0).
	      exemple:
			grep || ls: here ls is executed because grep has failed.
			ls || grep: here grep is not executed because ls has succeed.

	      error:
		    for && and || opperand, errors are identical as pipe.
		    if a command is missing, don't execute the command line and print:
		       Invalid null command.

inhibitors: \[special char(", `, ', \)]
	    backslash allow you to use special char of the shell (here ", ', `, \) and interpret them as special character and not their utility in the shell.
	    if backslash is at the end of the line, wait for user to complete the line.

globbings: (*|?)
	   * represent a string of every file/directory starting by all the character previous and after the * wildcard.
	    error:
		    if there is neither file or directory corresponding to the [prev]*[next] string:
		   [prev]*[next]: No match.

       ? represent only one charachter
	    error:
		    same as * wildcard.

backsticks: ``
        take the string between backsticks and execute it as a command, and replaces it's output in the command line
        if there is no string between backstring ignore it.

Parentheses: ()
        execute the command in parentheses in a sub shell.
        error:
            () ==> Invalid null command.
            () ls ==> Badly place ()'s.
