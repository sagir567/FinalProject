# Speech Emotion Recognition - Transformers - Wav2Vec2

**Complete Video Tutorial:** https://youtu.be/s5-8yeYJV7Y

# Project Information

This tutorial focuses on building a Speech Emotion Recognition (SER) system using Wugg2Vec2, a pre-trained model by Facebook AI, and Transformer models. The goal is to recognize emotions from spoken audio using advanced machine learning techniques.

There are a set of 200 target words were spoken in the carrier phrase "Say the word _' by two actresses (aged 26 and 64 years) and recordings were made of the set portraying each of seven emotions (anger, disgust, fear, happiness, pleasant surprise, sadness, and neutral). There are 2800 data points (audio files) in total.

The dataset is organised such that each of the two female actor and their emotions are contain within its own folder. And within that, all 200 target words audio file can be found. The format of the audio file is a WAV format.

### Output Attributes
- anger
- disgust
- fear
- happiness
- pleasant surprise
- sadness
- neutral

**Download link:** https://www.kaggle.com/ejlok1/toronto-emotional-speech-set-tess
**More Datasets:** https://www.kaggle.com/dmitrybabko/speech-emotion-recognition-en

# Libraries

- pandas
- matplotlib
- torch
- transformers
- librosa

# Neural Network

- Wav2Vec2 Transformers
  
**Accuracy:** 99.6