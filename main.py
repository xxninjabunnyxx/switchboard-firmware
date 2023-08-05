import machine
import sdcard
import uos

# Assign chip select (CS) pin (and start it high)
cs = machine.Pin(9, machine.Pin.OUT)

# Intialize SPI peripheral (start with 1 MHz)
spi = machine.SPI(1,
                  baudrate=1000000,
                  polarity=0,
                  phase=0,
                  bits=8,
                  firstbit=machine.SPI.MSB,
                  sck=machine.Pin(10),
                  mosi=machine.Pin(11),
                  miso=machine.Pin(8))

# Initialize SD card
sd = sdcard.SDCard(spi, cs)

# Mount filesystem
vfs = uos.VfsFat(sd)
uos.mount(vfs, "/sd")

# check to see if /sd/config.json exists
if "config.json" in uos.listdir("/sd"):
    with open("/sd/config.json", "r") as f:
        config = f.read()
else:
    with open("/sd/config.json", "w") as f:
        f.write('{}')
        f.close()
    with open("/sd/config.json", "r") as f:
        config = f.read()
