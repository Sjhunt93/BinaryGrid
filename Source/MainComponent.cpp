/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "MainComponent.h"

static const int STUFF[8] = {128,64,32,16,8,4,2,1};

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 700);
    setLookAndFeel(&version3);

    for (int i = 0; i < 24; i++) {
        addAndMakeVisible(buttons[i]);
        if (i < 16) {
            buttons[i].addListener(this);
        }
        
        buttons[i].setButtonText("0");
        buttons[i].setColour(TextButton::ColourIds::buttonOnColourId, Colours::red);
        buttons[i].setColour(TextButton::ColourIds::buttonColourId, Colours::white);
    }
    
    auto setUpBtn = [this](String text, TextButton & btn)
    {
        btn.addListener(this);
        addAndMakeVisible(btn);
        btn.setButtonText(text);
    };
    
    setUpBtn("&", bAnd);
    setUpBtn("|", bOr);
    setUpBtn("^", xOr);
    setUpBtn("~", bNot);
    
    
    addAndMakeVisible(l1);
    addAndMakeVisible(l2);
    addAndMakeVisible(l3);
    l1.setColour(Label::ColourIds::textColourId, Colours::white);
    l2.setColour(Label::ColourIds::textColourId, Colours::white);
    l3.setColour(Label::ColourIds::textColourId, Colours::white);
    
    addAndMakeVisible(bitShiftUp);
    bitShiftUp.addListener(this);
    bitShiftUp.setButtonText("<<");
    addAndMakeVisible(bitShiftDown);
    bitShiftDown.addListener(this);
    bitShiftDown.setButtonText(">>");
    bitShiftUp.setLookAndFeel(&version3);
    bitShiftDown.setLookAndFeel(&version3);
    
    addAndMakeVisible(bitShiftUp2);
    bitShiftUp2.addListener(this);
    bitShiftUp2.setButtonText("<<");
    addAndMakeVisible(bitShiftDown2);
    bitShiftDown2.addListener(this);
    bitShiftDown2.setButtonText(">>");
    bitShiftUp2.setLookAndFeel(&version3);
    bitShiftDown2.setLookAndFeel(&version3);
    
    
}


MainComponent::~MainComponent()
{
}

void MainComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));
    
    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    //    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    float height = getHeight() / 5.0;
    float width = (getWidth()-50.0) / 10.0;
    for (int i = 0; i < 8; i++) {
        buttons[i].setBounds(width*i + width, 0, width, height);
    }
    l1.setBounds(buttons[7].getRight() + 10, buttons[7].getY(), 40,100);
    for (int i = 8; i < 16; i++) {
        buttons[i].setBounds(width*(i%8) + width, height*2.0, width, height);
    }
    l2.setBounds(buttons[15].getRight() + 10, buttons[15].getY(), 40,100);
    for (int i = 16; i < 24; i++) {
        buttons[i].setBounds(width*(i%8) + width, height*3.5, width, height);
    }
    l3.setBounds(buttons[23].getRight() + 10, buttons[23].getY(), 40,100);
    bAnd.setBounds(200.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    bOr.setBounds(bAnd.getRight() + 10.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    xOr.setBounds(bOr.getRight() + 10.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    bNot.setBounds(xOr.getRight() + 10.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    bitShiftUp.setBounds(bNot.getRight() + 10.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    bitShiftDown.setBounds(bitShiftUp.getRight() + 10.0, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    
    bitShiftUp2.setBounds(bitShiftDown.getRight() + 50, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
    bitShiftDown2.setBounds(bitShiftUp2.getRight() + 10, buttons[0].getBottom() + 5.0, 50.0, height * 0.8);
}

void MainComponent::buttonClicked (Button* btn)
{
    if (btn == &bAnd) {
        updateAnd();
    }
    else if (btn == &bOr) {
        updateOr();
    }
    else if (btn == &xOr) {
        updateXOr();
    }
    else if (btn == &bNot) {
        updateNot ();
    }
    else if (btn == &bitShiftDown) {
        int data[8] = {0};
        for (int i = 0; i < 7; i++) {
            data[i+1] = buttons[i].getToggleState();
        }
        for (int i = 0; i < 8; i++) {
            buttons[i].setToggleState(data[i], dontSendNotification);
            buttons[i].setButtonText(String((int)buttons[i].getToggleState()));
        }
    }
    else if (btn == &bitShiftUp) {
        int data[8] = {0};
        for (int i = 1; i < 8; i++) {
            data[i-1] = buttons[i].getToggleState();
        }
        for (int i = 0; i < 8; i++) {
            buttons[i].setToggleState(data[i], dontSendNotification);
            buttons[i].setButtonText(String((int)buttons[i].getToggleState()));
        }
    }
    else if (btn == &bitShiftDown2) {
        int data[8] = {0};
        for (int i = 0; i < 7; i++) {
            data[i+1] = buttons[i+8].getToggleState();
        }
        for (int i = 0; i < 8; i++) {
            buttons[i+8].setToggleState(data[i], dontSendNotification);
            buttons[i+8].setButtonText(String((int)buttons[i+8].getToggleState()));
        }
    }
    else if (btn == &bitShiftUp2) {
        int data[8] = {0};
        for (int i = 1; i < 8; i++) {
            data[i-1] = buttons[i+8].getToggleState();
        }
        for (int i = 0; i < 8; i++) {
            buttons[i+8].setToggleState(data[i], dontSendNotification);
            buttons[i+8].setButtonText(String((int)buttons[i+8].getToggleState()));
        }
    }
    else {
        btn->setToggleState(!btn->getToggleState(), dontSendNotification);
        btn->setButtonText(String((int)btn->getToggleState()));
    }
    
    
    
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    for (int i = 0; i < 8; i++) {
        value1 += buttons[i].getToggleState() ? STUFF[i] : 0;
        value2 += buttons[i+8].getToggleState() ? STUFF[i] : 0;
        value3 += buttons[i+16].getToggleState() ? STUFF[i] : 0;
        
        
        
    }
    l1.setText(String(value1), dontSendNotification);
    l2.setText(String(value2), dontSendNotification);
    l3.setText(String(value3), dontSendNotification);
}

void MainComponent::updateOr ()
{
    for (int i = 0; i < 8; i++) {
        bool condition = buttons[i].getToggleState() || buttons[i+8].getToggleState();
        buttons[i+16].setToggleState(condition, dontSendNotification);
        buttons[i+16].setButtonText(String((int)buttons[i+16].getToggleState()));
        
    }
}
void MainComponent::updateXOr ()
{
    for (int i = 0; i < 8; i++) {
        bool condition = !buttons[i].getToggleState() != !buttons[i+8].getToggleState();
        buttons[i+16].setToggleState(condition, dontSendNotification);
        buttons[i+16].setButtonText(String((int)buttons[i+16].getToggleState()));
        
    }
}
void MainComponent::updateAnd ()
{
    for (int i = 0; i < 8; i++) {
        bool condition = buttons[i].getToggleState() && buttons[i+8].getToggleState();
        buttons[i+16].setToggleState(condition, dontSendNotification);
        buttons[i+16].setButtonText(String((int)buttons[i+16].getToggleState()));
    }
}

void MainComponent::updateNot ()
{
    for (int i = 0; i < 8; i++) {
        bool condition = !buttons[i].getToggleState();
        buttons[i+16].setToggleState(condition, dontSendNotification);
        buttons[i+16].setButtonText(String((int)buttons[i+16].getToggleState()));

    }
}
