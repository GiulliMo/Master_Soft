from pocketsphinx.pocketsphinx import *
import soundfile
from espnet_model_zoo.downloader import ModelDownloader
from espnet2.bin.asr_inference import Speech2Text
from libraries.asr import *

d = ModelDownloader()
speech2text = Speech2Text(**d.download_and_unpack("models/asr_train_asr_transformer_e18_raw_bpe_sp_valid.acc.best.zip"))

import os

asr = asr(language='gb')
MODELDIR = 'model_pocket'
config = Decoder.default_config()
config.set_string('-hmm', os.path.join(MODELDIR, 'en-us'))
config.set_string('-lm', os.path.join(MODELDIR, 'en-us.lm.bin'))
config.set_string('-dict', os.path.join(MODELDIR, 'cmudict-en-us.dict'))

# Creaders decoder object for streaming data.
decoder = Decoder(config)
wavfile = 'test.wav'

def decode_phrase(decoder):
    decoder.start_utt()
    stream = asr.getBuffer(w=wave.open(wavfile, 'r'))
    data16 = np.frombuffer(stream, dtype=np.float64)
    decoder.process_raw(data16,False,False)
    decoder.end_utt()
    words = []
    hypothesis = decoder.hyp()
    [words.append(seg.word) for seg in decoder.seg()]
    return hypothesis.hypstr


print(decode_phrase(decoder, wavfile))

speech, rate = soundfile.read(wavfile)

nbests = speech2text(speech)
text, *_ = nbests[0]
print(text)