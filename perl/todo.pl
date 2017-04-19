#!/usr/bin/perl

# Galen Helfter

$loc = "/home/ghelfte/Documents/todo.txt";
$helpstr = "Available options:\n\t* help (h) - prints help";

# Process any secondary commands:
# Available:
#   - help (h)
#   - add (a) - TODO
#   - clear (c) - TODO
#   - remove (r) - TODO
if (@ARGV.length > 0)
{
    $i = 0;
    # Go through all of the arguments
    while ($i < @ARGV.length)
    {
        ++$i;
        if (@ARGV[i] eq "h" or @ARGV[i] eq "help")
        {
            print "${helpstr}\n";
        }
    }
}

# If no secondary commands, just display the file
else
{
    open(LIST, "<${loc}");

    # Go through each line
    while (<LIST>)
    {
        print "$_";
    }

    close(LIST);
}
