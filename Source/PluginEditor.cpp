/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
MuteAudioProcessorEditor::MuteAudioProcessorEditor(MuteAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  setSize(200, 200);

  muteButton.setToggleState(audioProcessor.muted,
                            juce::NotificationType::dontSendNotification);
  muteButton.setButtonText("Mute");
  muteButton.changeWidthToFitText();

  muteButton.addListener(this);

  addAndMakeVisible(muteButton);
}

MuteAudioProcessorEditor::~MuteAudioProcessorEditor() {}

//==============================================================================
void MuteAudioProcessorEditor::paint(juce::Graphics &g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MuteAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  muteButton.setBounds(10, 10, 100, 100);
}

void MuteAudioProcessorEditor::buttonClicked(juce::Button *button){};

void MuteAudioProcessorEditor::buttonStateChanged(juce::Button *button) {
  audioProcessor.muted = muteButton.getToggleState();
};
