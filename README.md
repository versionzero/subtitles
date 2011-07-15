# YAPS: Yet Another Parser for Subtitles

The purpose of these tools is to help extract some meaningful data
from the volumes of subtitle files available on the web.

YAPS requires the ''Lingua::Stem'' Perl module, it can easily
installed like so:

    perl -MCPAN -e 'install Lingua::Stem'

For a complete index of where a word exists in a film, simply run the
following command line:

    ./yaps sample.srt | tee sample.words

Where ''sample.srt'' is a subtitle file.  The output will resemble the
following:

    been, 00:00:56.656
    failures, 00:00:56.656
    have, 00:00:56.656
    operations, 00:00:56.656
    recent, 00:00:56.656
    ...

And so on.  To generage some interesting information on the words and
their stems, run something similar to this:

    ./stem sample.words | tee sample.freq

The output will resemble the following:

    been, 1
    failur, 1
    have, 2
    oper, 1
    recent, 1
    your, 2
    about, 1
    ...

That's it.  One day this might actually be useful.

