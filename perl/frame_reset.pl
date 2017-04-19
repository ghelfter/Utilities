#!/usr/bin/perl

# Galen Helfter
# ghelfter@gmail.com
#
# This script will take three arguments
#  1) The Sequence name
#  2) The beginning frame
#  3) The ending frame
#  and it will reset them to start at zero, in case that's needed for
#  ffmpeg or any other such command. It is exclusive of the last frame,
#  so you'll have to go one past it (201 if 200 is the last frame)
#
#  Format:
#  ./frame_reset.pl [sequence] [start] [end]
#  Example:
#  ./frame_reset.pl Shot_06 62 201

if((@ARGV.length) < 3)
{
    print "Not an argument.\n"
}
else
{
    $startframe = int(@ARGV[1]);
    print "${startframe}\n";

    my $mlength = int(@ARGV[2]);
    $mlength -= $startframe;

    print "${mlength}\n";
    $i = 0;

    while($i < $mlength)
    {
        $filename = sprintf("%s.%4d.png", @ARGV[0], $i+$startframe);
        $filename =~ tr/ /0/;
        $new = sprintf("%s.%4d.png", @ARGV[0], $i);
        $new =~ tr/ /0/;

        system("mv", $filename, $new);
        $i += 1;
    }
}
