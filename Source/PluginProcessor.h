#pragma once

#include <JuceHeader.h>
#include "SynthVoice.h"

/**
    The main entrypoint class for handing audio processing for the synth.
    It wraps the Sythesiser class and handles all audio parameters that interface with the GUI.
*/
class FioreAudioProcessor  : public juce::AudioProcessor {
public:
    FioreAudioProcessor();
    ~FioreAudioProcessor() override;
    
    // AudioProcessor overrides
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorValueTreeState& getAPVTS();
    
    // Buncha JUCE garbage
   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    const juce::String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
private:
    juce::Synthesiser synth;
    juce::AudioProcessorValueTreeState apvts;
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParams();
    void updateParams();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FioreAudioProcessor)
};
