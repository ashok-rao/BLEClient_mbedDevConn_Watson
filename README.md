For instructions to get the BLE client working please refer to the repo: https://github.com/ashok-rao/BLE_Client_My_OPT3001.git

There is a slide deck in the repo that should help with an overview of the entire application. Please refer to this.

# Getting started with mbed Client on mbed OS

This is the mbed Client example for mbed OS. It demonstrates how to register a device with mbed Device Connector, how to read a device/resource and how to deregister. If you are unfamiliar with mbed Device Connector, it is recommended that you read [the introduction to the data model](https://docs.mbed.com/docs/mbed-device-connector-web-interfaces/en/latest/#the-mbed-device-connector-data-model) first.

The application:

* Connects to network via Ethernet connection.
* Registers with mbed Device Connector.
* Gives mbed Device Connector access to its resources (currently read only).
* Reads the light sensor's value & display the same using HTTP GET request.
* Connect to IBM Watson via API keys and relay the same data to IBM Watson.
* A Node-RED app is provided in the repo for import under Node-RED in Watson.
* Configuration of Watson and ARM mbed bridge under Watson is a topic separately dealt with.

## Required hardware

* NUCLEO_F429ZI target platform #(with hardware modification for SB121 and SB122 - the resistor needs to be shorted across SB122 since there is an SPI pin conflict between the arduino connector and the LAN controller).
* ST BLE shield (X-NUCLEO-IDB05A1)
* 1x micro-USB cable.
* Ethernet cable and connection to the internet.

## Supported Target hardware configurations

 This example has been tested in following configuration
 * NUCLEO_F429ZI (Ethernet)
 
Apart from this, this example can work on other mbed OS supported hardware boards which support any of the given network interface including Ethernet, WiFi, Mesh (6LoWPAN) or Thread, provided the configuration fulfills condition that the target hardware has TLS entropy implemented for it and the complete example configuration of mbed Client, selected network interface and mbed OS components fits into hardware's given memory size (Flash size and RAM size). 

## Requirements for non-K64F boards

*   This example requires TLS functionality to be enabled on mbed TLS.
    On devices where hardware entropy is not present, TLS is disabled by default.
    This would result in compile time failures or linking failures.

    To learn why entropy is required, read the
    [TLS Porting guide](https://docs.mbed.com/docs/mbed-os-handbook/en/5.2/advanced/tls_porting/).

## Required software

* [ARM mbed account](https://developer.mbed.org/account/login/?next=/).
* [mbed-cli](https://github.com/ARMmbed/mbed-cli) - to build the example programs. To learn how to build mbed OS applications with mbed-cli, see [the user guide](https://github.com/ARMmbed/mbed-cli/blob/master/README.md).
* [Serial port monitor](https://developer.mbed.org/handbook/SerialPC#host-interface-and-terminal-applications).
* IBM Watson account (free account is fine.)

## Application setup

To configure the example application:

1. [Select the connection type](#connection-type).
1. [Set the client credentials](#client-credentials).
1. [Change Ethernet settings](#ethernet-settings).
1. [Set up an IP address](#ip-address-setup). This step is optional.
1. [Change the socket type](#changing-socket-type). This step is optional.

### Connection type

The application uses Ethernet as the default connection type. To change the connection type, set one of them in `mbed_app.json`. For example, to enable 6LoWPAN ND mode:

```json
    "network-interface": {
        "help": "options are ETHERNET,WIFI,MESH_LOWPAN_ND,MESH_THREAD.",
        "value": "MESH_LOWPAN_ND"
    }
```

### Client credentials

To register the application with the Connector service, you need to create and set the client side certificate.

1. Go to [mbed Device Connector](https://connector.mbed.com) and log in with your mbed account.
1. On mbed Device Connector, go to [My Devices > Security credentials](https://connector.mbed.com/#credentials) and click the **Get my device security credentials** to get new credentials for your device.
1. Replace the contents in the `security.h` file of this project's directory with the content copied above.

### Ethernet settings

For running the example application using Ethernet, you need:

- An Ethernet cable.
- An Ethernet connection to the internet.

### IP address setup

This example uses IPv4 to communicate with the [mbed Device Connector Server](https://api.connector.mbed.com) except for 6LoWPAN ND and Thread. The example program should automatically get an IPv4 address from the router when connected over Ethernet.

If your network does not have DHCP enabled, you have to manually assign a static IP address to the board. We recommend having DHCP enabled to make everything run smoothly.

### Changing socket type

Your device can connect to mbed Device Connector via UDP or TCP binding mode. The default is UDP. The binding mode cannot be changed in 6LoWPAN ND or Thread mode.

To change the binding mode:

1. In the `simpleclient.h` file, find the parameter `SOCKET_MODE`. The default is `M2MInterface::UDP`.
1. To switch to TCP, change it to `M2MInterface::TCP`.
1. Rebuild and flash the application.

<span class="tips">**Tip:** The instructions in this document remain the same, irrespective of the socket mode you select.</span>

## Building the example

To build the example using mbed CLI:

1. Open a command line tool and navigate to the project’s directory.

2. Clone this repo.

3. [Configure](#application-setup) the client application.

4. To build the application, select the hardware board and build the toolchain using the command:

    ```
    mbed compile -m NUCLEO_F429ZI -t ARM -c
    ```

    mbed CLI builds a binary file under the project’s `BUILD/` directory.

5. Plug the Ethernet cable into the board if you are using Ethernet mode.

6. Plug the micro-USB cable into the board. The board is listed as a mass-storage device.

8. Drag the binary `BUILD/NUCLEO_F429ZI/ARM/*.bin` to the board to flash the application.

9. The board is automatically programmed with the new binary. A flashing LED on it indicates that it is still working. When the LED stops blinking, the board is ready to work.

10. Press the **Reset** button on the board to run the program.

11. For verification, continue to the [Monitoring the application](#monitoring-the-application) chapter.

## Monitoring the application

The application prints debug messages over the serial port, so you can monitor its activity with a serial port monitor. The application uses baud rate 9600.

<span class="notes">**Note:** Instructions to set this up are located [here](https://developer.mbed.org/handbook/SerialPC#host-interface-and-terminal-applications).</span>

After connecting, you should see messages about connecting to mbed Device Connector:

```
Starting mbed Client example...
Using <Network Interface>

Connected to Network successfully
IP address xxx.xxx.xxx.xxx

SOCKET_MODE : UDP
Connecting to coap://api.connector.mbed.com:5684

```

<span class="notes">**Note:** Device name is the endpoint name you will need later on when [testing the application](https://github.com/ARMmbed/mbed-os-example-client#testing-the-application).</span>

## Testing the application

1. Flash the application.
2. Verify that the registration succeeded. You should see `Registered object successfully!` printed to the serial port.
3. On mbed Device Connector, go to [My devices > Connected devices](https://connector.mbed.com/#endpoints). Your device should be listed here.
4. Go to [Device Connector > API Console](https://connector.mbed.com/#console).
5. Click the **Endpoint directory lookups** drop down menu.
![](/docs/img/ep_lookup.PNG) 
6. In the menu, click **GET** next to **Endpoint's resource representation**. Select your _endpoint_ and _resource-path_. For example, the _endpoint_ is the identifier of your endpoint that can be found in the `security.h` file as `MBED_ENDPOINT_NAME`. Choose `3200/0/5501`as a resource path and click **TEST API**. 
7. The value of the light sensror is shown.

<span class="tips">**Tip:** If you get an error, for example `Server Response: 410 (Gone)`, clear your browser's cache, log out, and log back in.</span>

<span class="notes">**Note:** Only GET methods can be executed through [Device Connector > API Console](https://connector.mbed.com/#console). For other methods, check the [mbed Device Connector Quick Start](https://github.com/ARMmbed/mbed-connector-api-node-quickstart).

### Application resources

The application exposes three [resources](https://docs.mbed.com/docs/mbed-device-connector-web-interfaces/en/latest/#the-mbed-device-connector-data-model):

1. `OPT/0/5501`. Light sensor's readings (GET).

To learn how to get notifications when resource 1 changes, or how to use resources 2 and 3, read the [mbed Device Connector Quick Start](https://github.com/ARMmbed/mbed-connector-api-node-quickstart).
