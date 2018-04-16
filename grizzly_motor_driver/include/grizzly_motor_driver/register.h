
#ifndef GRIZZLY_MOTOR_DRIVER_REGISTER_H
#define GRIZZLY_MOTOR_DRIVER_REGISTER_H

#include <stdint.h>
#include <string>

namespace grizzly_motor_driver
{

namespace Actions
{
  enum Action
  {
    Read = 0, // 0x00
    Write = 64, // 0x40
    Response = 128 // 0x80
  };
}  // namespace Actions
typedef Actions::Action Action;

// TODO(tbaltovski): Move out to different header.
namespace Registries
{
  enum Registry
  {
    StartUpErrors = 2,
    RunTimeErrors = 3,
    RegistryVer = 30,
    CkCityAddress = 31,
    SoftwareVer = 32,
    BdiSettings = 35,
    LowerBdiTripPoint = 36,
    UpperBdiReoverPoint = 37,
    PreChargeVoltage = 33,
    SystemVoltage = 34,
    BovTripPoint = 38,
    BovEnable = 39,
    AbsoluteCurrent = 40,
    PeakCurrent = 41,
    RatedCurrent = 42,
    RegenCurrent = 43,
    CoastCurrent = 44,
    MaxCurrentAllowTime = 45,
    MaxCurrentResetTime = 46,
    MaxSpeedForward = 50,
    MaxSpeedReverse = 51,
    LimpForwardSpeed = 56,
    LimpReverseSpeed = 57,
    AccelForward = 52,
    DecelForward = 53,
    AccelReverse = 54,
    DecelReverse = 55,
    Pot1ErrorOffset = 59,
    Pot1Mode = 60,
    Pot1Middle = 61,
    Pot1Min = 62,
    Pot1Max = 63,
    Pot1Shape = 64,
    Pot1BrokenWireDetect = 65,
    Pot1StopDeadBand = 66,
    Pot1RunDeadBand = 67,
    AnalogOutFunction = 90,
    AnalogOutVoltage = 91,
    SroDebounceTime = 83,
    NeutralToStopTime = 92,
    IOScanTime = 93,
    SafeSeqEnable = 94,
    IsoEnable = 95,
    IrComp = 96,
    MotorResistance = 97,
    IOActive = 98,
    KI = 99,
    KP = 100,
    HeartBeatEnabled = 101,
    HeartBeatTimer = 102,
    StatusUpdateEnable = 103,
    StatusUpdateTimer = 104,
    HeadingAckEnable = 105,
    Throt = 231,
    ForwardSw = 232,
    ReverseSw = 233,
    Heading = 234,
    HeadingNetSelect = 235,
    SroSw = 236,
    TargetPwm = 237,
    ActualCurrent = 238,
    BatVoltage = 239,
    Temperature = 240,
    BdiActive = 241,
    BrakeSw = 243,
    MotVoltage = 244,
    CurrentSensorZero = 245,
    BaseCharged = 246,
    ControllerEnabled = 247,
    ResetController = 248,
    StatusUpdate = 255,
    EnableKeySw = 500,
    CommandSpeed = 501
  };
}  // namespace Registries
typedef Registries::Registry Registry;

class Register
{
public:
  Register(const std::string &name, float initial, float min, float max, float scale);

  void setReceived();
  void clearReceived();
  bool wasReceived() const;
  void setData(float data);
  float sendData() const;
  float getData() const;
  void setRawData(int32_t data);
  int32_t getRawData() const;
  float sendInitial() const;
  float getInitial() const;
  int32_t getRawInitial() const;

private:
  std::string name_;
  float min_;
  float max_;
  float initial_;
  int32_t raw_initial_;
  float data_;
  int32_t raw_data_;
  float scale_;
  bool received_;
};

}  // namespace grizzly_motor_driver

#endif  // GRIZZLY_MOTOR_DRIVER_REGISTER_H
