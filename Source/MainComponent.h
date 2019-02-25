/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainComponent   : public Component , public TextButton::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();
    
    void paint (Graphics&);
    void resized();
    
    void buttonClicked (Button* btn);
    
    void updateOr ();
    void updateXOr ();
    void updateAnd ();
    void updateNot ();
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    LookAndFeel_V3 version3;
    TextButton buttons[24];
    TextButton bAnd, bOr, xOr, bNot, bitShiftUp, bitShiftDown, bitShiftUp2, bitShiftDown2;
    Label       l1,l2,l3;
};


#endif  // MAINCOMPONENT_H_INCLUDED
