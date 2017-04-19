#!/usr/bin/perl

# Galen Helfter
# Copyright 2017
# glpipe.pl

if (@ARGV.length > 0)
{
    $i = 0;
    # Go through all of the arguments
    if (@ARGV[0] eq "init") 
    {
        system("mkdir", "drawing");
        system("mkdir", "model");
        system("mkdir", "render");
        system("mkdir", "surface");
    }
    elsif(@ARGV[0] eq "open")
    {
        if(@ARGV.length > 1)
        {
            # Get file extension
            my ($front, $bline) = split(/\./, @ARGV[1]);
            if($bline eq "blend")
            {
                system("blender", @ARGV[1]);
            }
            elsif($bline eq "svg")
            {
                system("inkscape", @ARGV[1]);
            }
            elsif($bline eq "kra")
            {
                system("krita", @ARGV[1]);
            }
        }
        else
        {
            print "Filename not specified.\n";
        }
    }
}

else
{
    print "Error, not enough arguments\n";
}
