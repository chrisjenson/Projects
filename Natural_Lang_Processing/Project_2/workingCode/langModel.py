import re
from random import randint
import math
import random

# For whenever an unaccounted for word or char occurs
UNK = None
# Sentence identifiers
SENTENCE_START = '<s>'
SENTENCE_END = '</s>'

# Function that processes an input text file and outputs the result as text file
def preprocess_file(input_file, output_file):
    with open(input_file, 'r') as f, open(output_file, 'w') as fo:
        for line in f:
            fo.write(line.replace(' ,',' ').replace(',',' ')
                .replace(' \'\' ',' ').replace('\n',' ').replace(' .', ' </s>\n<s>').replace('.', '')
                .replace('\\/', ' ').replace(' \'', '\'').replace(' `` ',' ').replace('`` ','')
                .replace(' \'\' ', ' ').replace('$', ' ').replace(' $ ', ' ').replace('%', ' ').replace(' % ', ' ')
                .replace('\'', '').replace(' ; ', ' ').replace(' - ', ' ').replace(' & ', ' ').replace(' ` ', '')
                .replace(' :', '').replace(':', '').replace(' :','').replace('--',' ').replace(' -- ',' ')
                .replace(':','').replace('  ',' ').replace('?', ' </s>\n<s>').replace('!', ' </s>\n<s>')
                .replace(' ?', ' </s>\n<s>').replace(' !', ' </s>\n<s>'))

# Function to read a file from a given file path
def read_sentences_from_file(file_path):
    with open(file_path, "r") as f:
        return [re.split("\s+", line.rstrip('\n')) for line in f]

# Unigram Model class declaration
class UnigramLanguageModel:
    # Declare Model Initialization
    def __init__(self, sentences, smoothing = False):
        self.unigram_frequencies = dict()
        self.corpus_length = 0
       
        # Adjust frequency of each word in each sentence by 1
        for sentence in sentences:
            for word in sentence:
                self.unigram_frequencies[word] = self.unigram_frequencies.get(word, 0) + 1
                
                # Adjust corpus length if current word is not a sentence marker
                if ((word != SENTENCE_START) and (word != SENTENCE_END)):
                    self.corpus_length += 1
        
        # Subtract 2 as unigram_frequencies dict contains value for <s> and </s>
        self.unique_words = (len(self.unigram_frequencies) - 2)
        self.smoothing = smoothing

    # Function to calculate word unigram probability
    def calculate_unigram_probability(self, word):
            word_probability_numerator = self.unigram_frequencies.get(word, 0)
            word_probability_denominator = self.corpus_length
           
            # Checks if smoothing is enabled           
            if (self.smoothing):
                word_probability_numerator += 1
                # Add one to total unique words for UNK - unknown occurances
                word_probability_denominator += self.unique_words + 1
           
            # Return a floating point number representative of the word's probability
            return (float(word_probability_numerator) / float(word_probability_denominator))

    # Function to calculate the probability that a given word occurs in a sentence
    def calculate_sentence_probability(self, sentence, normalize_probability = True):
        sentence_probability_log_sum = 0
        
        # Adjust probability of each word that is not a sentence marker
        for word in sentence:
            if ((word != SENTENCE_START) and (word != SENTENCE_END)):
                word_probability = self.calculate_unigram_probability(word)
                sentence_probability_log_sum += math.log(word_probability, 2)
        
        # Return 2^sentence probability sum if we are normalizing, else just return the original sentence prob sum
        return math.pow(2, sentence_probability_log_sum) if normalize_probability else sentence_probability_log_sum                

    # Function to initialize, sort, and clean input vocabulary
    def sorted_vocabulary(self):
        full_vocab = list(self.unigram_frequencies.keys())
        full_vocab.remove(SENTENCE_START)
        full_vocab.remove(SENTENCE_END)
        full_vocab.sort()
        full_vocab.append(UNK)
        full_vocab.append(SENTENCE_START)
        full_vocab.append(SENTENCE_END)
        return full_vocab

# Bigram Model class declaration
class BigramLanguageModel(UnigramLanguageModel):
    # Initialization function declaration
    def __init__(self, sentences, smoothing = False):
        UnigramLanguageModel.__init__(self, sentences, smoothing)
        self.bigram_frequencies = dict()
        self.unique_bigrams = set()
        
        # Adjust frequency of all words in all sentences by 1 unless they are sentence markers
        for sentence in sentences:
            previous_word = None
            
            for word in sentence:
                if (previous_word != None):
                    self.bigram_frequencies[(previous_word, word)] = self.bigram_frequencies.get((previous_word, word), 0) + 1
                    
                    # Checks for sentence markers
                    if ((previous_word != SENTENCE_START) and (word != SENTENCE_END)):
                        self.unique_bigrams.add((previous_word, word))
                
                # Assign the current word to the previous word
                previous_word = word
       
        # Subtract two for the uni model as the unigram_frequencies dict
        # Contains a value for <s> and </s>, these need to be included in bigram
        self.unique__bigram_words = len(self.unigram_frequencies)

    # Function to calculate word bigram probability
    def calculate_bigram_probabilty(self, previous_word, word):
        bigram_word_probability_numerator = self.bigram_frequencies.get((previous_word, word), 0)
        bigram_word_probability_denominator = self.unigram_frequencies.get(previous_word, 0)
       
        # Checks if smoothing is enabled
        if (self.smoothing):
            bigram_word_probability_numerator += 1
            bigram_word_probability_denominator += self.unique__bigram_words
        
        # Return a floating point number representative of the word's probability or 0 if either num or denom is 0
        return 0.0 if( (bigram_word_probability_numerator == 0) or (bigram_word_probability_denominator == 0)) else (float(
            bigram_word_probability_numerator) / float(bigram_word_probability_denominator))

    # Function to calculate the probability that a given word occurs in a sentence
    def calculate_bigram_sentence_probability(self, sentence, normalize_probability = True):
        bigram_sentence_probability_log_sum = 0
        previous_word = None

        # Adjust probability of each word that is not a sentence marker
        for word in sentence:
            # Checks if a given word is the first word in its sentence
            if (previous_word != None):
                bigram_word_probability = self.calculate_bigram_probabilty(previous_word, word)
                bigram_sentence_probability_log_sum += math.log(bigram_word_probability, 2)
            
            previous_word = word

        # Return 2^sentence probability sum if we are normalizing, else just return the original sentence prob sum
        return math.pow(2, bigram_sentence_probability_log_sum) if normalize_probability else bigram_sentence_probability_log_sum

# Calculate number of unigrams
def calculate_number_of_unigrams(sentences):
    unigram_count = 0
    
    # Fix the length of each sentence according to sentence markers
    for sentence in sentences:
        # Subtract two for <s> and </s>
        unigram_count += len(sentence) - 2
    
    # Return the unigram count
    return unigram_count

# Calculate number of bigrams
def calculate_number_of_bigrams(sentences):
        bigram_count = 0
        
        for sentence in sentences:
            # Subtract one for number of bigrams in the sentence
            bigram_count += len(sentence) - 1
       
        return bigram_count

# Function to print the Unigram probabilities
def print_unigram_probs(sorted_vocab_keys, model, word_1):
    # Find the right key in the sorted list
    for vocab_key in sorted_vocab_keys:
        # If the key matches, print and calculate the probability, can be <s> or </s>
        if (vocab_key == word_1):
            print("{}: {}".format(vocab_key if vocab_key != UNK else 'UNK',
                                       model.calculate_unigram_probability(vocab_key)), end=' ')

# Function to print the Bigram probabilities
def print_bigram_probs(sorted_vocab_keys, model, word_1, word_2):
    # Match both words
    for vocab_key in sorted_vocab_keys:
        # If the key matches and the first word isnt the end of a sentence
        if ((vocab_key != SENTENCE_END) and (vocab_key == word_1)):
            print((word_1 + ', ' + word_2) if vocab_key != UNK else 'UNK', end=': ')
            
            for vocab_key_second in sorted_vocab_keys:
                # If the second word isnt the start of the sentence and the word matches
                if ((vocab_key_second != SENTENCE_START) and (vocab_key_second == word_2)):
                    print("{0:.5f}".format(model.calculate_bigram_probabilty(vocab_key, vocab_key_second)), end="\t\t")

# Find top 10 unigrams
def find_top_ten_unigrams(sorted_vocab_keys, model):
    prob_dict = {}
    top_ten = {}
    
    # Loop through each key
    for vocab_key in sorted_vocab_keys:
        #Find the probability
        prob = (model.calculate_unigram_probability(vocab_key))

        # Trying to shorten the dictionary a bit
        if(prob > 0.005):
            prob_dict[vocab_key] = prob
    
    # Loop through 10 indexes
    for index in range(10):
        # Get max key
        top_key = max(prob_dict, key = prob_dict.get)
        # Get that keys value
        top_value = prob_dict[top_key]
        # Remove the top key while storing it into the top ten list with its probability
        top_ten[top_key] = prob_dict.pop(top_key)

    print('Top Ten Unigrams:\n' + str(top_ten))

# Function to find top 10 biigrams
# Note that this function takes about a minute
def find_top_ten_bigrams(sorted_vocab_keys, model):
    prob_dict = {}
    top_ten = {}
    
    # Loop through each key
    for vocab_key in sorted_vocab_keys:
        for vocab_key_second in sorted_vocab_keys:
            # Find the probability
            prob = (model.calculate_bigram_probabilty(vocab_key, vocab_key_second))

            # Trying to shorten the dictionary a bit
            if(prob > 0.001):
                prob_dict[str(vocab_key) + ', ' + str(vocab_key_second)] = prob
    
    # Loop through 10 indexes
    for index in range(10):
        # Get max key
        top_key = max(prob_dict, key = prob_dict.get)
        # Remove the top key while storing it into the top ten list with its probability
        top_ten[top_key] = prob_dict.pop(top_key)

    print('\nTop Ten Bigrams:\n' + str(top_ten))

# Function to calculate perplexity for unigrams
def calculate_unigram_perplexity(model, sentences):
    #Find the number of unigrams
    unigram_count = calculate_number_of_unigrams(sentences)
    sentence_probability_log_sum = 0
    
    # Loop through each sentence
    for sentence in sentences:
        try:
            # Calculate using log to try avoiding underflow and better performance
            sentence_probability_log_sum -= math.log(model.calculate_sentence_probability(sentence), 2)
        
        # Exception for underflow
        except:
            sentence_probability_log_sum -= float('-inf')
    
    # Finish the calculation, equivalent to math done int class
    return math.pow(2, (sentence_probability_log_sum / unigram_count))

# Function to calculate perplexity for bigrams
def calculate_bigram_perplexity(model, sentences):
    # Find the number of unigrams
    number_of_bigrams = calculate_number_of_bigrams(sentences)
    bigram_sentence_probability_log_sum = 0
    
    # For each sentence
    for sentence in sentences:
        try:
            # Calculate using log to try avoiding underflow and better performance
            bigram_sentence_probability_log_sum -= math.log(model.calculate_bigram_sentence_probability(sentence), 2)
        
        # Exception for underflow
        except:
            bigram_sentence_probability_log_sum -= float('-inf')
    
    # Finish the calculation, equivalent to math done int class
    return math.pow(2, (bigram_sentence_probability_log_sum / number_of_bigrams))

# Function to generate sentences with weighted probability given a set of sorted keys and a Language Model
def generate_sentence(sorted_vocab_keys, model):
    sent = ['<s>']
    
    # Picks a random starting word for the sentence
    curWord = sorted_vocab_keys[randint(0, len(sorted_vocab_keys))]

    # Find next word, ends at the end sentnce symbol
    while ((sent[-1] != '</s>')):
        # Find the next word using weighted probability
        nextWord = find_weighted_next_word(sorted_vocab_keys, model, curWord)
        sent.append(nextWord)
        curWord = nextWord

    print('Generated sentence: \n' + str(sent))
    return sent

# Function to use weighted probability in chosing the next word in a sentence
def find_weighted_next_word(sorted_vocab_keys, model, word):
    prob_dict = {}
    top_words = {}
    
    for vocab_key in sorted_vocab_keys:
        # Find the probability
        prob = (model.calculate_bigram_probabilty(word, vocab_key))

        # Trying to shorten the dictionary a bit
        if(prob > 0.0001):
            prob_dict[str(vocab_key)] = prob
    
    for index in range(5):
        # Get max key
        top_key = max(prob_dict, key = prob_dict.get)

        # Remove the top key while storing it into the top ten list with its probability
        top_words[top_key] = prob_dict.pop(top_key)

    # Normalize the top five probabilities out of 100 
    sum = 0
    for value in top_words:
        sum = top_words[value] + sum
    for value2 in top_words:
        top_words[value2] = ((top_words[value2] / sum) * 100)

    # Get seperate lists for the keys and values
    list_of_keys = list(top_words.keys())
    list_of_values = list(top_words.values())

    # Return a list of weighted selection results given, values, weights, and list length
    selection = random.choices(list_of_keys, list_of_values, k=1)

    return selection[0]

# The code should ask for the directory/file name of both these files
# Will be commented out for testings sake
#dataset = read_sentences_from_file('training2.txt')
#dataset_test = read_sentences_from_file('test.txt')
dataset = read_sentences_from_file(input('Enter the path to the training text file: '))
dataset_test = read_sentences_from_file(input('Enter the path to the test text file: '))

# Given the training and test files, create the models
dataset_model_unsmoothed = BigramLanguageModel(dataset)
dataset_model_smoothed = BigramLanguageModel(dataset, smoothing = True)

# Get sorted list of the lexicon
sorted_vocab_keys = dataset_model_unsmoothed.sorted_vocabulary()

# Get the words desired by the user for uni/bigram calculations
uni_word = input('\nEnter your word for unigram: ')
bi_word_1 = input('Enter first bigram word: ')
bi_word_2 = input('Enter second bigram word: ')

# Print/calculate unsmoothed uni/bigram probability
print('\n-  Unsmoothed Unigram  -')
print_unigram_probs(sorted_vocab_keys, dataset_model_unsmoothed, uni_word)
print('\n\n-  Unsmoothed Bigram  -')
print_bigram_probs(sorted_vocab_keys, dataset_model_unsmoothed, bi_word_1, bi_word_2)

keepGoing = str(input('\n\nCalculate smoothed uni/bigram probability? (yes/no): '))
if (keepGoing == 'yes'):
    print('\n-  Smoothed Unigram  -')
    print_unigram_probs(sorted_vocab_keys, dataset_model_smoothed, uni_word)
    print('\n\n-  Smoothed Bigram -')
    print_bigram_probs(sorted_vocab_keys, dataset_model_smoothed, bi_word_1, bi_word_2)

keepGoing = str(input('\n\nCalculate Perplexity? (yes/no): '))
if (keepGoing == 'yes'):
    # For perplexity calculation
    bigram_dataset_model_smoothed = BigramLanguageModel(dataset, smoothing = True)

    # Print and calculate perplexity for uni/bigrams
    print('\n-  Perplexity of test.txt  -')
    print('unigram: ', calculate_unigram_perplexity(bigram_dataset_model_smoothed, dataset_test))
    print('bigram: ', calculate_bigram_perplexity(bigram_dataset_model_smoothed, dataset_test))

# Will call and print generated unsmoothed sentences
#print('\n- Unsmoothed -')
#generate_sentence(sorted_vocab_keys, dataset_model_unsmoothed)
#generate_sentence(sorted_vocab_keys, dataset_model_unsmoothed)
#generate_sentence(sorted_vocab_keys, dataset_model_unsmoothed)
#generate_sentence(sorted_vocab_keys, dataset_model_unsmoothed)
#generate_sentence(sorted_vocab_keys, dataset_model_unsmoothed)

keepGoing = str(input('\nGenerate Smoothed Sentences? (yes/no): '))
if (keepGoing == 'yes'):
    print('\n-  Smoothed Sentences  -')
    # Will call and print generated smoothed sentences
    generate_sentence(sorted_vocab_keys, dataset_model_smoothed)
    generate_sentence(sorted_vocab_keys, dataset_model_smoothed)
    generate_sentence(sorted_vocab_keys, dataset_model_smoothed)
    generate_sentence(sorted_vocab_keys, dataset_model_smoothed)
    generate_sentence(sorted_vocab_keys, dataset_model_smoothed)

keepGoing = str(input('Find top ten smoothed/unsmoothed uni/bigrams? (yes/no): '))
if (keepGoing == 'yes'):
    # Will find and print the top ten uni/bigrams with their probabilities
    print('\n- Unsmoothed -')
    find_top_ten_unigrams(sorted_vocab_keys, dataset_model_unsmoothed)
    find_top_ten_bigrams(sorted_vocab_keys, dataset_model_unsmoothed)
    print('\n- Smoothed -')
    find_top_ten_unigrams(sorted_vocab_keys, dataset_model_smoothed)
    find_top_ten_bigrams(sorted_vocab_keys, dataset_model_smoothed)