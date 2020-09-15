from pocketsphinx.pocketsphinx import *
from sphinxbase.sphinxbase import *

import os


MODELDIR = 'model_pocket'
config = Decoder.default_config()
config.set_string('-hmm', os.path.join(MODELDIR, 'en-us'))
config.set_string('-lm', os.path.join(MODELDIR, 'en-us.lm.bin'))
config.set_string('-dict', os.path.join(MODELDIR, 'cmudict-en-us.dict'))

# Creaders decoder object for streaming data.
decoder = Decoder(config)
wavfile = 'test.wav'

def decode_phrase(decoder, wav_file):
    decoder.start_utt()
    stream = open(wav_file, "rb")
    while True:
        buf = stream.read(1024)
        if buf:
            decoder.process_raw(buf, False, False)
        else:
            break
    decoder.end_utt()
    words = []
    [words.append(seg.word) for seg in decoder.seg()]
    return words

print(decode_phrase(decoder, wavfile))