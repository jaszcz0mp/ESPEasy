#ifndef ESPEASY_DEFAULTS_H_
#define ESPEASY_DEFAULTS_H_

/*
    To modify the stock configuration without changing this repo file :
    - define USE_CUSTOM_H as a build flags. ie : export PLATFORMIO_BUILD_FLAGS="'-DUSE_CUSTOM_H'"
    - add a "Custom.h" file in this folder.

*/
#ifdef USE_CUSTOM_H
#include "Custom.h"
#endif

// ********************************************************************************
//   User specific configuration
// ********************************************************************************

// Set default configuration settings if you want (not mandatory)
// You can always change these during runtime and save to eeprom
// After loading firmware, issue a 'reset' command to load the defaults.
// --- Basic Config Settings ------------------------------------------------------------------------
#ifndef DEFAULT_NAME
#define DEFAULT_NAME        "ESP_Easy"          // Enter your device friendly name
#endif
#ifndef UNIT
#define UNIT                0                   // Unit Number
#endif
#ifndef DEFAULT_DELAY
#define DEFAULT_DELAY       60                  // Sleep Delay in seconds
#endif

// --- Wifi AP Mode (when your Wifi Network is not reachable) ----------------------------------------
#ifndef DEFAULT_AP_IP
#define DEFAULT_AP_IP       192,168,4,1         // Enter IP address (comma separated) for AP (config) mode
#endif
#ifndef DEFAULT_AP_SUBNET
#define DEFAULT_AP_SUBNET   255,255,255,0       // Enter IP address (comma separated) for AP (config) mode
#endif
#ifndef DEFAULT_AP_KEY
#define DEFAULT_AP_KEY      "configesp"         // Enter network WPA key for AP (config) mode
#endif

// --- Wifi Client Mode -----------------------------------------------------------------------------
#ifndef DEFAULT_SSID
#define DEFAULT_SSID        "ssid"              // Enter your Wifi network SSID
#endif
#ifndef DEFAULT_KEY
#define DEFAULT_KEY         "wpakey"            // Enter your Wifi network WPA key
#endif
#ifndef DEFAULT_USE_STATIC_IP
#define DEFAULT_USE_STATIC_IP   false           // (true|false) enabled or disabled static IP
#endif
#ifndef DEFAULT_IP
#define DEFAULT_IP          "192.168.0.50"      // Enter your IP address
#endif
#ifndef DEFAULT_DNS
#define DEFAULT_DNS         "192.168.0.1"       // Enter your DNS
#endif
#ifndef DEFAULT_GW
#define DEFAULT_GW          "192.168.0.1"       // Enter your Gateway
#endif
#ifndef DEFAULT_SUBNET
#define DEFAULT_SUBNET      "255.255.255.0"     // Enter your Subnet
#endif
#ifndef DEFAULT_IPRANGE_LOW
#define DEFAULT_IPRANGE_LOW  "0.0.0.0"          // Allowed IP range to access webserver
#endif
#ifndef DEFAULT_IPRANGE_HIGH
#define DEFAULT_IPRANGE_HIGH "255.255.255.255"  // Allowed IP range to access webserver
#endif
#ifndef DEFAULT_IP_BLOCK_LEVEL
#define DEFAULT_IP_BLOCK_LEVEL 1                // 0: ALL_ALLOWED  1: LOCAL_SUBNET_ALLOWED  2: ONLY_IP_RANGE_ALLOWED
#endif
#ifndef DEFAULT_ADMIN_USERNAME
#define DEFAULT_ADMIN_USERNAME  "admin"
#endif

#ifndef DEFAULT_WIFI_CONNECTION_TIMEOUT
#define DEFAULT_WIFI_CONNECTION_TIMEOUT  10000  // minimum timeout in ms for WiFi to be connected.
#endif
#ifndef DEFAULT_WIFI_FORCE_BG_MODE
#define DEFAULT_WIFI_FORCE_BG_MODE       false  // when set, only allow to connect in 802.11B or G mode (not N)
#endif
#ifndef DEFAULT_WIFI_RESTART_WIFI_CONN_LOST
#define DEFAULT_WIFI_RESTART_WIFI_CONN_LOST  false // Perform wifi off and on when connection was lost.
#endif
#ifndef DEFAULT_ECO_MODE
#define DEFAULT_ECO_MODE                 false   // When set, make idle calls between executing tasks.
#endif
#ifndef DEFAULT_WIFI_NONE_SLEEP
#define DEFAULT_WIFI_NONE_SLEEP          false  // When set, the wifi will be set to no longer sleep (more power used and need reboot to reset mode)
#endif
#ifndef DEFAULT_GRATUITOUS_ARP
#define DEFAULT_GRATUITOUS_ARP           false  // When set, the node will send periodical gratuitous ARP packets to announce itself.
#endif

// --- Default Controller ------------------------------------------------------------------------------
#ifndef DEFAULT_CONTROLLER
#define DEFAULT_CONTROLLER   false              // true or false enabled or disabled, set 1st controller defaults
#endif
// using a default template, you also need to set a DEFAULT PROTOCOL to a suitable MQTT protocol !
#ifndef DEFAULT_PUB
#define DEFAULT_PUB         "sensors/espeasy/%sysname%/%tskname%/%valname%" // Enter your pub
#endif
#ifndef DEFAULT_SUB
#define DEFAULT_SUB         "sensors/espeasy/%sysname%/#" // Enter your sub
#endif
#ifndef DEFAULT_SERVER
#define DEFAULT_SERVER      "192.168.0.8"       // Enter your Server IP address
#endif
#ifndef DEFAULT_PORT
#define DEFAULT_PORT        8080                // Enter your Server port value
#endif

#ifndef DEFAULT_PROTOCOL
#define DEFAULT_PROTOCOL    0                   // Protocol used for controller communications
                                                //   0 = Stand-alone (no controller set)
                                                //   1 = Domoticz HTTP
                                                //   2 = Domoticz MQTT
                                                //   3 = Nodo Telnet
                                                //   4 = ThingSpeak
                                                //   5 = Home Assistant (openHAB) MQTT
                                                //   6 = PiDome MQTT
                                                //   7 = EmonCMS
                                                //   8 = Generic HTTP
                                                //   9 = FHEM HTTP
#endif

#ifndef DEFAULT_PIN_I2C_SDA
#define DEFAULT_PIN_I2C_SDA              4
#endif
#ifndef DEFAULT_PIN_I2C_SCL
#define DEFAULT_PIN_I2C_SCL              5
#endif

#ifndef DEFAULT_PIN_STATUS_LED
#define DEFAULT_PIN_STATUS_LED           -1
#endif
#ifndef DEFAULT_PIN_STATUS_LED_INVERSED
#define DEFAULT_PIN_STATUS_LED_INVERSED  true
#endif



// --- Advanced Settings ---------------------------------------------------------------------------------
#if defined(ESP32)
  #define USE_RTOS_MULTITASKING
#endif
#ifdef M5STACK_ESP
//  #include <M5Stack.h>
#endif

#ifndef DEFAULT_USE_RULES
#define DEFAULT_USE_RULES                       false   // (true|false) Enable Rules?
#endif
#ifndef DEFAULT_RULES_OLDENGINE
#define DEFAULT_RULES_OLDENGINE                true
#endif

#ifndef DEFAULT_MQTT_RETAIN
#define DEFAULT_MQTT_RETAIN                     false   // (true|false) Retain MQTT messages?
#endif
#ifndef DEFAULT_MQTT_DELAY
#define DEFAULT_MQTT_DELAY                      100    // Time in milliseconds to retain MQTT messages
#endif
#ifndef DEFAULT_MQTT_LWT_TOPIC
#define DEFAULT_MQTT_LWT_TOPIC                  ""      // Default lwt topic
#endif
#ifndef DEFAULT_MQTT_LWT_CONNECT_MESSAGE
#define DEFAULT_MQTT_LWT_CONNECT_MESSAGE        "Connected" // Default lwt message
#endif
#ifndef DEFAULT_MQTT_LWT_DISCONNECT_MESSAGE
#define DEFAULT_MQTT_LWT_DISCONNECT_MESSAGE     "Connection Lost" // Default lwt message
#endif
#ifndef DEFAULT_MQTT_USE_UNITNAME_AS_CLIENTID
#define DEFAULT_MQTT_USE_UNITNAME_AS_CLIENTID   0
#endif

#ifndef DEFAULT_USE_NTP
#define DEFAULT_USE_NTP                         false   // (true|false) Use NTP Server
#endif
#ifndef DEFAULT_NTP_HOST
#define DEFAULT_NTP_HOST                        ""              // NTP Server Hostname
#endif
#ifndef DEFAULT_TIME_ZONE
#define DEFAULT_TIME_ZONE                       0               // Time Offset (in minutes)
#endif
#ifndef DEFAULT_USE_DST
#define DEFAULT_USE_DST                         false   // (true|false) Use Daily Time Saving
#endif

#ifndef DEFAULT_SYSLOG_IP
#define DEFAULT_SYSLOG_IP                       ""                      // Syslog IP Address
#endif
#ifndef DEFAULT_SYSLOG_LEVEL
#define DEFAULT_SYSLOG_LEVEL            0                               // Syslog Log Level
#endif
#ifndef DEFAULT_SERIAL_LOG_LEVEL
#define DEFAULT_SERIAL_LOG_LEVEL        LOG_LEVEL_INFO                  // Serial Log Level
#endif
#ifndef DEFAULT_WEB_LOG_LEVEL
#define DEFAULT_WEB_LOG_LEVEL           LOG_LEVEL_INFO                  // Web Log Level
#endif
#ifndef DEFAULT_SD_LOG_LEVEL
#define DEFAULT_SD_LOG_LEVEL            0                               // SD Card Log Level
#endif
#ifndef DEFAULT_USE_SD_LOG
#define DEFAULT_USE_SD_LOG                      false                   // (true|false) Enable Logging to the SD card
#endif

#ifndef DEFAULT_USE_SERIAL
#define DEFAULT_USE_SERIAL                      true    // (true|false) Enable Logging to the Serial Port
#endif
#ifndef DEFAULT_SERIAL_BAUD
#define DEFAULT_SERIAL_BAUD                     115200  // Serial Port Baud Rate
#endif
#ifndef DEFAULT_SYSLOG_FACILITY
#define DEFAULT_SYSLOG_FACILITY               	0 	    // kern
#endif

/*
// --- Experimental Advanced Settings (NOT ACTIVES at this time) ------------------------------------

#define DEFAULT_USE_GLOBAL_SYNC                 false           // (true|false)
#define DEFAULT_SYNC_UDP_PORT                   0                       //

#define DEFAULT_IP_OCTET                        0                       //
#define DEFAULT_WD_IC2_ADDRESS                  0                       //
#define DEFAULT_USE_SSDP                        false           // (true|false)
#define DEFAULT_CON_FAIL_THRES                  0                       //
#define DEFAULT_I2C_CLOCK_LIMIT                 0                       //
*/

#endif // ESPEASY_DEFAULTS_H_