// ---- Class TwoChannelJoyStick

#ifndef CLASSTwoChannelJoyStick_H
#define CLASSTwoChannelJoyStick_H

const int buffer_size = 10; 
int _ch1_buffer[buffer_size];
int _ch2_buffer[buffer_size];

class TwoChannelJoyStick {
  public:
    TwoChannelJoyStick(byte ch1_pin, byte ch2_pin){
      pinMode(ch1_pin, INPUT);
      pinMode(ch2_pin, INPUT);
      _ch1_pin = ch1_pin;
      _ch2_pin = ch2_pin;

      for (int i = 0; i < buffer_size; i++){
        _ch1_buffer[i] = 0;
        _ch2_buffer[i] = 0;
      }
    }

    TwoChannelJoyStick(byte ch1_pin, byte ch2_pin, byte aux1_pin, byte aux2_pin){
      pinMode(ch1_pin, INPUT);
      pinMode(ch2_pin, INPUT);
      _ch1_pin = ch1_pin;
      _ch2_pin = ch2_pin;

      pinMode(aux1_pin, INPUT);
      pinMode(aux2_pin, INPUT);
      _aux1_pin = aux1_pin;
      _aux2_pin = aux2_pin;

      for (int i = 0; i < buffer_size; i++){
        _ch1_buffer[i] = 0;
        _ch2_buffer[i] = 0;
      }
    }

    int channel_1_8bit(){
      int ch1_servo = int(pulseIn(_ch1_pin, HIGH) - _mid);
      bool is_positve = ch1_servo >= 0;
      ch1_servo = abs(ch1_servo) - _mid_delta;
      
      if (ch1_servo < 0) ch1_servo = 0;
      if (ch1_servo > _pike) ch1_servo = _pike;

      pop(_ch1_buffer, ch1_servo);
      int _copy[buffer_size];
      for (int i = 0; i < buffer_size; i++){
        _copy[i] = _ch1_buffer[i];
      }
      bubbleSort(_copy);
      ch1_servo = _copy[buffer_size/2];

      int value = map(ch1_servo, 0, _pike, 0, 254);
      if (is_positve){
        return value;
      } else {
        return -value;
      }
    }

    int channel_2_8bit(){
      int ch2_servo = int(pulseIn(_ch2_pin, HIGH) - _mid);
      bool is_positve = ch2_servo >= 0;
      ch2_servo = abs(ch2_servo) - _mid_delta;
      
      if (ch2_servo < 0) ch2_servo = 0;
      if (ch2_servo > _pike) ch2_servo = _pike;

      pop(_ch2_buffer, ch2_servo);
      int _copy[buffer_size];
      for (int i = 0; i < buffer_size; i++){
        _copy[i] = _ch2_buffer[i];
      }
      bubbleSort(_copy);
      ch2_servo = _copy[buffer_size/2];

      int value = map(ch2_servo, 0, _pike, 0, 254);
      if (is_positve){
        return value;
      } else {
        return -value;
      }
    }

    bool aux1_on(){
      return analogRead(_aux1_pin) > 300;
    }

    bool aux2_on(){
      return analogRead(_aux2_pin) > 300;
    }

  private:
    byte _ch1_pin;
    byte _ch2_pin;
    byte _aux1_pin;
    byte _aux2_pin;

    int _mid = 1500;
    int _high = 2000;
    int _low = 1000;
    int _mid_delta = 150;
    int _pike = _high-_mid-_mid_delta;

    void pop(int arr[], int val) {
      for (int i = 0; i < buffer_size - 1; i++) {
        arr[i] = arr[i+1];
      }
      arr[buffer_size-1] = val;
    }
    void bubbleSort(int arr[]) {
      for (int i = 0; i < buffer_size - 1; i++) {
        for (int j = 0; j < buffer_size - i - 1; j++) {
          if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
          }
        }
      }
    }


};
#endif