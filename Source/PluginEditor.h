/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"
#include <JuceHeader.h>

//==============================================================================
/**
 */
class MuteAudioProcessorEditor : public juce::AudioProcessorEditor,
                                 private juce::Button::Listener {
public:
  MuteAudioProcessorEditor(MuteAudioProcessor &);
  ~MuteAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  MuteAudioProcessor &audioProcessor;

  juce::ToggleButton muteButton;

  void buttonClicked(juce::Button *button) override;
  void buttonStateChanged(juce::Button *button) override;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MuteAudioProcessorEditor)
};
