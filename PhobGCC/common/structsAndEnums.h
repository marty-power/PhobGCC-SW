#ifndef ENUMS_H
#define ENUMS_H
#pragma once

#include <stdint.h>

enum JumpConfig {
	DEFAULTJUMP,
	SWAP_XZ,
	SWAP_YZ,
	SWAP_XL,
	SWAP_YL,
	SWAP_XR,
	SWAP_YR
};

enum WhichTrigger {
	LTRIGGER,
	RTRIGGER
};

enum Increase {
	INCREASE,
	DECREASE
};

enum WhichAxis {
	XAXIS,
	YAXIS
};

enum WhichStick {
	ASTICK,
	CSTICK
};

enum HardReset {
	HARD,
	SOFT,
	FACTORY
};

enum NotchStatus {
	TERT_INACTIVE,
	TERT_ACTIVE,
	SECONDARY,
	CARDINAL
};

enum ExtrasSlot{
	EXTRAS_UP,
	EXTRAS_DOWN,
	EXTRAS_LEFT,
	EXTRAS_RIGHT,
	EXTRAS_SIZE,
	EXTRAS_UNSET
};

union IntOrFloat{
	int intValue;
	float floatValue;
};

struct ExtrasConfig{
	IntOrFloat config[4];
};

struct Pins{
	int pinLa;
	int pinRa;
	int pinL;
	int pinR;
	int pinAx;
	int pinAy;
	int pinCx;
	int pinCy;
	int pinRX;
	int pinTX;
	int pinDr;
	int pinDu;
	int pinDl;
	int pinDd;
	int pinX;
	int pinY;
	int pinA;
	int pinB;
	int pinZ;
	int pinS;
};

enum Buttons : uint16_t {
	A = (1 << 15) | 1,
	B = (1 << 14) | 1,
	X = (1 << 13) | 1,
	Y = (1 << 12) | 1,
	S = (1 << 11) | 1,
	Dl = (1 << 7) | 1,
	Dr = (1 << 6) | 1,
	Dd = (1 << 5) | 1,
	Du = (1 << 4) | 1,
	Z = (1 << 3) | 1,
	R = (1 << 2) | 1,
	L = (1 << 1) | 1
};

enum ControllerCommand : uint16_t {
	SAFE_MODE = A | X | Y | S,
	DISPLAY_VERSION = A | Z | Du,
	SOFT_RESET = A | B | Z | S,
	HARD_RESET = A | B | Z | Dd,
	AUTO_INIT = A | X | Y | Z,
	TOURNAMENT_TOGGLE = Z | S,
	INCREASE_RUMBLE = A | B | Du,
	DECREASE_RUMBLE = A | B | Dd,
	DISPLAY_RUMBLE_SETTING = A | B | S,
	ANALOG_STICK_CALIBRATION = A | X | Y | L,
	C_STICK_CALIBRATION = A | X | Y | R,
	ADVANCE_CALIBRATION = A | L | R,
	UNDO_CALIBRATION = Z,
	SKIP_TO_NOTCH_ADJ = S,
	NOTCH_ADJUST_CW = X,
	NOTCH_ADJUST_CCW = Y,
	NOTCH_ADJUST_RESET = B,
	INCREASE_ANALOG_X_SNAPBACK_FILTER = A | X | Du,
	DECREASE_ANALOG_X_SNAPBACK_FILTER = A | X | Dd,
	INCREASE_ANALOG_Y_SNAPBACK_FILTER = A | Y | Du,
	DECREASE_ANALOG_Y_SNAPBACK_FILTER = A | Y | Dd,
	INCREASE_ANALOG_X_WAVESHAPING = L | X | Du,
	DECREASE_ANALOG_X_WAVESHAPING = L | X | Dd,
	INCREASE_ANALOG_Y_WAVESHAPING = L | Y | Du,
	DECREASE_ANALOG_Y_WAVESHAPING = L | Y | Dd,
	INCREASE_ANALOG_X_SMOOTHING = R | X | Du,
	DECREASE_ANALOG_X_SMOOTHING = R | X | Dd,
	INCREASE_ANALOG_Y_SMOOTHING = R | Y | Du,
	DECREASE_ANALOG_Y_SMOOTHING = R | Y | Dd,
	DISPLAY_ANALOG_FILTER_SETTING = L | S,
	INCREASE_ANALOG_SCALER = L | A | Du,
	DECREASE_ANALOG_SCALER = L | A | Dd,
	INCREASE_ANALOG_CARDINAL_SNAPPING = R | A | Du,
	DECREASE_ANALOG_CARDINAL_SNAPPING = R | A | Dd,
	INCREASE_C_STICK_X_SNAPBACK_FILTER = A | X | Du | Z,
	DECREASE_C_STICK_X_SNAPBACK_FILTER = A | X | Dd | Z,
	INCREASE_C_STICK_Y_SNAPBACK_FILTER = A | Y | Du | Z,
	DECREASE_C_STICK_Y_SNAPBACK_FILTER = A | Y | Dd | Z,
	INCREASE_C_STICK_X_WAVESHAPING = L | X | Du | Z,
	DECREASE_C_STICK_X_WAVESHAPING = L | X | Dd | Z,
	INCREASE_C_STICK_Y_WAVESHAPING = L | Y | Du | Z,
	DECREASE_C_STICK_Y_WAVESHAPING = L | Y | Dd | Z,
	INCREASE_C_STICK_X_OFFSET = R | X | Du | Z,
	DECREASE_C_STICK_X_OFFSET = R | X | Dd | Z,
	INCREASE_C_STICK_Y_OFFSET = R | Y | Du | Z,
	DECREASE_C_STICK_Y_OFFSET = R | Y | Dd | Z,
	DISPLAY_C_STICK_FILTER_SETTING = R | S,
	INCREASE_C_STICK_SCALER = L | A | Du | Z,
	DECREASE_C_STICK_SCALER = L | A | Dd | Z,
	INCREASE_C_STICK_CARDINAL_SNAPPING = R | A | Du | Z,
	DECREASE_C_STICK_CARDINAL_SNAPPING = R | A | Dd | Z,
	SWAP_X_Z = X | Z | S,
	SWAP_Y_Z = Y | Z | S,
	SWAP_X_L = X | L | S,
	SWAP_Y_L = Y | L | S,
	SWAP_X_R = X | R | S,
	SWAP_Y_R = Y | R | S,
	CHANGE_L_TRIGGER_MODE = A | B | L,
	CHANGE_R_TRIGGER_MODE = A | B | R,
	INCREASE_L_TRIGGER_OFFSET = L | B | Du,
	DECREASE_L_TRIGGER_OFFSET = L | B | Dd,
	INCREASE_R_TRIGGER_OFFSET = R | B | Du,
	DECREASE_R_TRIGGER_OFFSET = R | B | Dd,
};

union ButtonState{
	uint8_t arr[10];
	struct {

		// byte 0
		uint8_t A : 1;
		uint8_t B : 1;
		uint8_t X : 1;
		uint8_t Y : 1;
		uint8_t S : 1;
		uint8_t orig : 1;
		uint8_t errL : 1;
		uint8_t errS : 1;

		// byte 1
		uint8_t Dl : 1;
		uint8_t Dr : 1;
		uint8_t Dd : 1;
		uint8_t Du : 1;
		uint8_t Z : 1;
		uint8_t R : 1;
		uint8_t L : 1;
		uint8_t high : 1;

		//byte 2-7
		uint8_t Ax : 8;
		uint8_t Ay : 8;
		uint8_t Cx : 8;
		uint8_t Cy : 8;
		uint8_t La : 8;
		uint8_t Ra : 8;

		// magic byte 8 & 9 (only used in origin cmd)
		// have something to do with rumble motor status???
		// ignore these, they are magic numbers needed
		// to make a cmd response work
		uint8_t magic1 : 8;
		uint8_t magic2 : 8;
	};
};

struct HardwareButtons{
	uint8_t L;
	uint8_t R;
	uint8_t Z;
	uint8_t X;
	uint8_t Y;
};

struct RawStick{
	float axRaw;
	float ayRaw;
	float cxRaw;
	float cyRaw;
	float axLinearized;
	float ayLinearized;
	float cxLinearized;
	float cyLinearized;
	float axUnfiltered;
	float ayUnfiltered;
	float cxUnfiltered;
	float cyUnfiltered;
};

struct Cardinals{
	uint8_t l : 1;
	uint8_t r : 1;
	uint8_t u : 1;
	uint8_t d : 1;
};

struct ControlConfig{
	JumpConfig jumpConfig;
	const int jumpConfigMin;
	const int jumpConfigMax;
	int lConfig;
	int rConfig;
	const int triggerConfigMin;
	const int triggerConfigMax;
	const int triggerDefault;
	int lTriggerOffset;
	int rTriggerOffset;
	const int triggerMin;
	const int triggerMax;
	int cXOffset;
	int cYOffset;
	const int cMax;
	const int cMin;
	int rumble;//0 is off, nonzero is on, higher is stronger
	const int rumbleMin;
	const int rumbleMax;
	const int rumbleDefault;
	const int rumbleFactory;
	bool safeMode;
	int autoInit;
	int lTrigInitial;
	int rTrigInitial;
	int xSnapback;//0 disables the filter entirely, 4 is default
	int ySnapback;
	const int snapbackMin;
	const int snapbackMax;
	const int snapbackDefault;
	const int snapbackFactoryAX;
	const int snapbackFactoryAY;
	int axSmoothing;
	int aySmoothing;
	int cxSmoothing;
	int cySmoothing;
	const int smoothingMin;
	const int smoothingMax;
	const int snapbackFactoryCX;
	const int snapbackFactoryCY;
	const int smoothingFactoryAX;
	const int smoothingFactoryAY;
	int axWaveshaping;
	int ayWaveshaping;
	int cxWaveshaping;
	int cyWaveshaping;
	const int waveshapingMin;
	const int waveshapingMax;
	const int waveshapingFactoryAX;
	const int waveshapingFactoryAY;
	const int waveshapingFactoryCX;
	const int waveshapingFactoryCY;
	int astickCardinalSnapping;
	int cstickCardinalSnapping;
	const int cardinalSnappingMin;
	const int cardinalSnappingMax;
	const int cardinalSnappingDefault;
	int astickAnalogScaler;
	int cstickAnalogScaler;
	const int analogScalerMin;
	const int analogScalerMax;
	const int analogScalerDefault;
	int tournamentToggle;
	const int tournamentToggleMin;
	const int tournamentToggleMax;
#ifdef PICO_RP2040
	int interlaceOffset;
	const int interlaceOffsetMin;
	const int interlaceOffsetMax;
#endif //PICO_RP2040
	ExtrasConfig extras[EXTRAS_SIZE];
};

struct FilterGains {
	//What's the max stick distance from the center
	float maxStick;
	//filtered velocity terms
	//how fast the filtered velocity falls off in the absence of stick movement.
	//Probably don't touch this.
	float xVelDecay;//0.1 default for 1.2ms timesteps, larger for bigger timesteps
	float yVelDecay;
	//how much the current position disagreement impacts the filtered velocity.
	//Probably don't touch this.
	float xVelPosFactor;//0.01 default for 1.2ms timesteps, larger for bigger timesteps
	float yVelPosFactor;
	//how much to ignore filtered velocity when computing the new stick position.
	//DO CHANGE THIS
	//Higher gives shorter rise times and slower fall times (more pode, less snapback)
	float xVelDamp;//0.125 default for 1.2ms timesteps, smaller for bigger timesteps
	float yVelDamp;
	//speed and accel thresholds below which we try to follow the stick better
	//These may need tweaking according to how noisy the signal is
	//If it's noisier, we may need to add additional filtering
	//If the timesteps are *really small* then it may need to be increased to get
	//  above the noise floor. Or some combination of filtering and playing with
	//  the thresholds.
	float velThresh;//1 default for 1.2ms timesteps, larger for bigger timesteps
	float accelThresh;//5 default for 1.2ms timesteps, larger for bigger timesteps
	//This just applies a low-pass filter.
	//The purpose is to provide delay for single-axis ledgedashes.
	//Must be between 0 and 1. Larger = more smoothing and delay.
	float xSmoothing;
	float ySmoothing;
	//Same thing but for C-stick
	float cXSmoothing;
	float cYSmoothing;
};

struct StickParams{
	//these are the linearization coefficients
	float fitCoeffsX[4];
	float fitCoeffsY[4];

	//these are the notch remap parameters
	float affineCoeffs[16][4]; //affine transformation coefficients for all regions of the stick
	float boundaryAngles[16]; //angles at the boundaries between regions of the stick (in the plane)
};

enum CaptureMode{
	CM_NULL,//do nothing
	CM_REACTION,//record immediately
	CM_STICK_RISE2,//starting when a stick coord exceeds a threshold distance from center; 100 pt 2-axis
	CM_STICK_RISE,//starting when a stick coord exceeds a threshold distance from center
	CM_STICK_FALL,//starting when a stick coord falls below a threshold
	CM_STICK_PIVOT,//starting when a stick coord falls below a threshold
	CM_TRIG,//increasing threshold on triggers
	CM_JUMP,//x, y, or melee tap jump threshold
	CM_PRESS,//any button press
};

enum GraphVar{
	GV_AX,//a-stick x-axis filtered & unfiltered
	GV_AY,
	GV_AXY,//a-stick x and y, only filtered
	GV_CX,
	GV_CY,
	GV_CXY,
	GV_L,
	GV_R,
};

struct DataCapture{
	//these are the params
	CaptureMode mode;
	WhichStick triggerStick;
	WhichStick captureStick;
	WhichAxis whichAxis;
	uint8_t stickmap;//which stickmap to display
	GraphVar graphVar;//which variable to graph
	bool begin;
	bool triggered;
	bool done;
	bool autoRepeat;
	uint32_t delay;//for recording reaction time
	uint8_t stickThresh;
	uint8_t triggerThresh;
	uint8_t startIndex;
	uint8_t endIndex;
	uint8_t viewIndex;//for stepping through manually and looking at coordinates and button presses
	uint8_t a1[100];//6 frames for analog
	uint8_t a2[100];
	uint8_t a1Unfilt[100];
	uint8_t a2Unfilt[100];
	uint8_t abxyszrl[200];//12 frames
	uint8_t axaycxcyrl[200];//12 frames
	float percents[3];
};

#endif //ENUMS_H
