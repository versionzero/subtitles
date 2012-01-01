# YAPS: Yet Another Parser for Subtitles

The purpose of these tools is to help extract some meaningful data
from the volumes of subtitle files available on the web.

YAPS et al. requires the ''Lingua::Stem'' Perl module, it can easily
installed like so:

    perl -MCPAN -e 'install Lingua::Stem'
    perl -MCPAN -e 'install Tie::Handle::CSV'

To parse a file for later processing, simply run the following command
line:

    $ cat sample.srt | srt2text

Where ''sample.srt'' is a subtitle file.  The output will resemble the
following:

    your recent operations have been failures
    i have doubts about
    your present proposal
    yes sir
    governor in my opinion this is an dumb move
    ...

And so on.  What it shows is the normalized version of the original
subtitles.  To generage some interesting information on the words,
type the following:

    $ cat sample.srt | srt2text | freq-map 

The output will resemble the following:

    your 1
    recent 1
    operations 1
    have 1
    been 1
    failures 1
    i 1
    ...

Note that there will be repeated words.  This is expected.  The
''freq-map'' command simply sets the frequency of each word it
encouters to 1.  The reduce step bellow does all the heavy lifting.

To compleate the frequency count, the reduce function must be used.
This sums the occurances of each word and prints out the frequencies
of words in alphabetic order.

The following is the compleate command line for the entire workflow:

    $ cat sample.srt | srt2text | freq-map | freq-reduce

The output will resemble the map step, but with frequencies >= 1, like
so:

    governor 1
    have 2
    i 1
    in 1
    is 1...

We use this multi-step approach so that we can bundle several analysis
steps together.  For instance, ''freq-reduce'' can take any size of
input with repeating or unique words and any integer frequency.  It
will always produce output that merges and sum the any non-unique
word.  Thus, given 100 subtitle files, it would produce a single
agregate to represent them all.

That's it.  One day this might actually be useful.

