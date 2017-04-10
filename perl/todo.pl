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
    while($i < @ARGV.length)
    {
        ++$i;
        if(@ARGV[i] eq "h" or @ARGV[i] eq "help")
        {
            print "${helpstr}\n";
        }
    }
}
else
{
    open(LIST, "<${loc}");
    while(<LIST>)
    {
        print "$_";
    }

    close(LIST);
}
