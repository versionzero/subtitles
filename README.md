# YAPS: Yet Another Parser for Subtitles

The purpose of these tools is to help extract some meaningful data
from the volumes of subtitle files available on the web.

YAPS et al. requires the ''Lingua::Stem'' Perl module, it can easily
installed like so:

    perl -MCPAN -e 'install Lingua::Stem'

For a complete index of where a word exists in a film, simply run the
following command line:

    $ ./yaps sample.srt | tee sample.words

Where ''sample.srt'' is a subtitle file.  The output will resemble the
following:

    your, 0, 00:00:56.656
    recent, 1, 00:00:56.656
    operations, 2, 00:00:56.656
    have, 3, 00:00:56.656
    been, 4, 00:00:56.656
    failures, 5, 00:00:56.656
    ...

And so on.  What it shows is the word, it's order in the original
subtitle sentence and the start time of the subtitle.  To generage
some interesting information on the words and their stems, type the
following:

    $ ./stem sample.words >|sample.stems 2>|sample.freq

The ''sample.stem'' output will resemble the following:

    your, your, 0, 00:00:56.656
    recent, recent, 1, 00:00:56.656
    operations, oper, 2, 00:00:56.656
    have, have, 3, 00:00:56.656
    been, been, 4, 00:00:56.656
    failures, failur, 5, 00:00:56.656
    ...

The ''sample.freq'' should resemble:

    your, 2
    recent, 1
    oper, 1
    have, 2
    been, 1
    failur, 1
    ...

That's it.  One day this might actually be useful.

