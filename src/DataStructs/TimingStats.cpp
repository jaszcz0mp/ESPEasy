#include "DataStructs/TimingStats.h"
#include "ESPEasy_common.h"
#include "ESPEasy_plugindefs.h"
#include "_CPlugin_Helper.h"

TimingStats::TimingStats() : _timeTotal(0.0), _count(0), _maxVal(0), _minVal(4294967295) {}

void TimingStats::add(unsigned long time) {
  _timeTotal += time;
  ++_count;

  if (time > _maxVal) { _maxVal = time; }

  if (time < _minVal) { _minVal = time; }
}

void TimingStats::reset() {
  _timeTotal = 0.0;
  _count     = 0;
  _maxVal    = 0;
  _minVal    = 4294967295;
}

bool TimingStats::isEmpty() const {
  return _count == 0;
}

float TimingStats::getAvg() const {
  if (_count == 0) { return 0.0; }
  return _timeTotal / _count;
}

unsigned int TimingStats::getMinMax(unsigned long& minVal, unsigned long& maxVal) const {
  if (_count == 0) {
    minVal = 0;
    maxVal = 0;
    return 0;
  }
  minVal = _minVal;
  maxVal = _maxVal;
  return _count;
}

bool TimingStats::thresholdExceeded(unsigned long threshold) const {
  if (_count == 0) {
    return false;
  }
  return _maxVal > threshold;
}

/********************************************************************************************\
   Functions used for displaying timing stats
 \*********************************************************************************************/
String getPluginFunctionName(int function) {
  switch (function) {
    case PLUGIN_INIT_ALL:              return F("INIT_ALL");
    case PLUGIN_INIT:                  return F("INIT");
    case PLUGIN_READ:                  return F("READ");
    case PLUGIN_ONCE_A_SECOND:         return F("ONCE_A_SECOND");
    case PLUGIN_TEN_PER_SECOND:        return F("TEN_PER_SECOND");
    case PLUGIN_DEVICE_ADD:            return F("DEVICE_ADD");
    case PLUGIN_EVENTLIST_ADD:         return F("EVENTLIST_ADD");
    case PLUGIN_WEBFORM_SAVE:          return F("WEBFORM_SAVE");
    case PLUGIN_WEBFORM_LOAD:          return F("WEBFORM_LOAD");
    case PLUGIN_WEBFORM_SHOW_VALUES:   return F("WEBFORM_SHOW_VALUES");
    case PLUGIN_GET_DEVICENAME:        return F("GET_DEVICENAME");
    case PLUGIN_GET_DEVICEVALUENAMES:  return F("GET_DEVICEVALUENAMES");
    case PLUGIN_WRITE:                 return F("WRITE");
    case PLUGIN_EVENT_OUT:             return F("EVENT_OUT");
    case PLUGIN_WEBFORM_SHOW_CONFIG:   return F("WEBFORM_SHOW_CONFIG");
    case PLUGIN_SERIAL_IN:             return F("SERIAL_IN");
    case PLUGIN_UDP_IN:                return F("UDP_IN");
    case PLUGIN_CLOCK_IN:              return F("CLOCK_IN");
    case PLUGIN_TIMER_IN:              return F("TIMER_IN");
    case PLUGIN_FIFTY_PER_SECOND:      return F("FIFTY_PER_SECOND");
    case PLUGIN_SET_CONFIG:            return F("SET_CONFIG");
    case PLUGIN_GET_DEVICEGPIONAMES:   return F("GET_DEVICEGPIONAMES");
    case PLUGIN_EXIT:                  return F("EXIT");
    case PLUGIN_GET_CONFIG:            return F("GET_CONFIG");
    case PLUGIN_UNCONDITIONAL_POLL:    return F("UNCONDITIONAL_POLL");
    case PLUGIN_REQUEST:               return F("REQUEST");
  }
  return getUnknownString();
}

bool mustLogFunction(int function) {
  switch (function) {
    case PLUGIN_INIT_ALL:              return false;
    case PLUGIN_INIT:                  return false;
    case PLUGIN_READ:                  return true;
    case PLUGIN_ONCE_A_SECOND:         return true;
    case PLUGIN_TEN_PER_SECOND:        return true;
    case PLUGIN_DEVICE_ADD:            return false;
    case PLUGIN_EVENTLIST_ADD:         return false;
    case PLUGIN_WEBFORM_SAVE:          return false;
    case PLUGIN_WEBFORM_LOAD:          return false;
    case PLUGIN_WEBFORM_SHOW_VALUES:   return false;
    case PLUGIN_GET_DEVICENAME:        return false;
    case PLUGIN_GET_DEVICEVALUENAMES:  return false;
    case PLUGIN_WRITE:                 return true;
    case PLUGIN_EVENT_OUT:             return true;
    case PLUGIN_WEBFORM_SHOW_CONFIG:   return false;
    case PLUGIN_SERIAL_IN:             return true;
    case PLUGIN_UDP_IN:                return true;
    case PLUGIN_CLOCK_IN:              return false;
    case PLUGIN_TIMER_IN:              return true;
    case PLUGIN_FIFTY_PER_SECOND:      return true;
    case PLUGIN_SET_CONFIG:            return false;
    case PLUGIN_GET_DEVICEGPIONAMES:   return false;
    case PLUGIN_EXIT:                  return false;
    case PLUGIN_GET_CONFIG:            return false;
    case PLUGIN_UNCONDITIONAL_POLL:    return false;
    case PLUGIN_REQUEST:               return true;
  }
  return false;
}

String getCPluginCFunctionName(int function) {
  switch (function) {
    case CPLUGIN_PROTOCOL_ADD:              return F("CPLUGIN_PROTOCOL_ADD");
    case CPLUGIN_PROTOCOL_TEMPLATE:         return F("CPLUGIN_PROTOCOL_TEMPLATE");
    case CPLUGIN_PROTOCOL_SEND:             return F("CPLUGIN_PROTOCOL_SEND");
    case CPLUGIN_PROTOCOL_RECV:             return F("CPLUGIN_PROTOCOL_RECV");
    case CPLUGIN_GET_DEVICENAME:            return F("CPLUGIN_GET_DEVICENAME");
    case CPLUGIN_WEBFORM_SAVE:              return F("CPLUGIN_WEBFORM_SAVE");
    case CPLUGIN_WEBFORM_LOAD:              return F("CPLUGIN_WEBFORM_LOAD");
    case CPLUGIN_GET_PROTOCOL_DISPLAY_NAME: return F("CPLUGIN_GET_PROTOCOL_DISPLAY_NAME");
    case CPLUGIN_TASK_CHANGE_NOTIFICATION:  return F("CPLUGIN_TASK_CHANGE_NOTIFICATION");
    case CPLUGIN_INIT:                      return F("CPLUGIN_INIT");
    case CPLUGIN_UDP_IN:                    return F("CPLUGIN_UDP_IN");
  }
  return getUnknownString();
}

bool mustLogCFunction(int function) {
  switch (function) {
    case CPLUGIN_PROTOCOL_ADD:              return false;
    case CPLUGIN_PROTOCOL_TEMPLATE:         return false;
    case CPLUGIN_PROTOCOL_SEND:             return true;
    case CPLUGIN_PROTOCOL_RECV:             return true;
    case CPLUGIN_GET_DEVICENAME:            return false;
    case CPLUGIN_WEBFORM_SAVE:              return false;
    case CPLUGIN_WEBFORM_LOAD:              return false;
    case CPLUGIN_GET_PROTOCOL_DISPLAY_NAME: return false;
    case CPLUGIN_TASK_CHANGE_NOTIFICATION:  return false;
    case CPLUGIN_INIT:                      return false;
    case CPLUGIN_UDP_IN:                    return true;
  }
  return false;
}

String getMiscStatsName(int stat) {
  switch (stat) {
    case LOADFILE_STATS:          return F("Load File");
    case SAVEFILE_STATS:          return F("Save File");
    case LOOP_STATS:              return F("Loop");
    case PLUGIN_CALL_50PS:        return F("Plugin call 50 p/s");
    case PLUGIN_CALL_10PS:        return F("Plugin call 10 p/s");
    case PLUGIN_CALL_10PSU:       return F("Plugin call 10 p/s U");
    case PLUGIN_CALL_1PS:         return F("Plugin call  1 p/s");
    case SENSOR_SEND_TASK:        return F("SensorSendTask()");
    case SEND_DATA_STATS:         return F("sendData()");
    case COMPUTE_FORMULA_STATS:   return F("Compute formula");
    case PROC_SYS_TIMER:          return F("proc_system_timer()");
    case SET_NEW_TIMER:           return F("setNewTimerAt()");
    case TIME_DIFF_COMPUTE:       return F("timeDiff()");
    case MQTT_DELAY_QUEUE:        return F("Delay queue MQTT");
    case TRY_CONNECT_HOST_TCP:    return F("try_connect_host() (TCP)");
    case TRY_CONNECT_HOST_UDP:    return F("try_connect_host() (UDP)");
    case HOST_BY_NAME_STATS:      return F("hostByName()");
    case CONNECT_CLIENT_STATS:    return F("connectClient()");
    case LOAD_CUSTOM_TASK_STATS:  return F("LoadCustomTaskSettings()");
    case WIFI_ISCONNECTED_STATS:  return F("WiFi.isConnected()");
    case WIFI_NOTCONNECTED_STATS: return F("WiFi.isConnected() (fail)");
    case LOAD_TASK_SETTINGS:      return F("LoadTaskSettings()");
    case TRY_OPEN_FILE:           return F("TryOpenFile()");
    case SPIFFS_GC_SUCCESS:       return F("SPIFFS GC success");
    case SPIFFS_GC_FAIL:          return F("SPIFFS GC fail");
    case RULES_PROCESSING:        return F("rulesProcessing()");
    case GRAT_ARP_STATS:          return F("sendGratuitousARP()");
    case BACKGROUND_TASKS:        return F("backgroundtasks()");
    case HANDLE_SCHEDULER_IDLE:   return F("handle_schedule() idle");
    case HANDLE_SCHEDULER_TASK:   return F("handle_schedule() task");
    case C001_DELAY_QUEUE:
    case C002_DELAY_QUEUE:
    case C003_DELAY_QUEUE:
    case C004_DELAY_QUEUE:
    case C005_DELAY_QUEUE:
    case C006_DELAY_QUEUE:
    case C007_DELAY_QUEUE:
    case C008_DELAY_QUEUE:
    case C009_DELAY_QUEUE:
    case C010_DELAY_QUEUE:
    case C011_DELAY_QUEUE:
    case C012_DELAY_QUEUE:
    case C013_DELAY_QUEUE:
    case C014_DELAY_QUEUE:
    case C015_DELAY_QUEUE:
    case C016_DELAY_QUEUE:
    case C017_DELAY_QUEUE:
    case C018_DELAY_QUEUE:
    case C019_DELAY_QUEUE:
    case C020_DELAY_QUEUE:
    {
      String result;
      result.reserve(16);
      result  = F("Delay queue ");
      result += get_formatted_Controller_number(static_cast<int>(stat - C001_DELAY_QUEUE + 1));
      return result;
    }
  }
  return getUnknownString();
}
