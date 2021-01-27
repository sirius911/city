#! /usr/bin/python

# A simple Python command line tool to control an MCP23017 I2C IO Expander
# By Nathan Chantrell http://nathan.chantrell.net
# GNU GPL V3 

import smbus
import sys
import getopt
 
bus = smbus.SMBus(1) # For revision 1 Raspberry Pi, change to bus = smbus.SMBus(1) for revision 2.

address = 0x21 # I2C address of MCP23017
bus.write_byte_data(0x21,0x00,0x00) # Set all of bank A to outputs 
bus.write_byte_data(0x21,0x01,0x00) # Set all of bank B to outputs 

# Handle the command line arguments
def main():
   try:
      opts, args = getopt.getopt(sys.argv[1:],"hb:o:s:",["bank=","output=","state="])

      if not opts:
        sys.exit(2)

   except getopt.GetoptError:
      sys.exit(2)

   for opt, arg in opts:
      if opt in ("-b", "--bank"):
         bank = arg
      elif opt in ("-o", "--output"):
         output = int(arg)
      elif opt in ("-s", "--state"):
         state = arg

# Set the correct register for the banks
   if bank == "a" :
    register = 0x12
   elif bank == "b" :
    register = 0x13
   else:
    sys.exit()

# Read current values from the IO Expander
   value =  bus.read_byte_data(address,register) 

# Shift the bits for the register value, checking if they are already set first
   if state == "high":
    if (value >> output) & 1 :
     sys.exit()
    else:
      value += (1 << output)
   elif state == "low":
    if (value >> output) & 1 :
     value -= (1 << output)
    else:
     sys.exit()
   else:
    sys.exit()

# Now write to the IO expander
   bus.write_byte_data(address,register,value)
 
# Tell them what we did
   print "Output GP"+bank.upper()+str(output), "changed to", state

if __name__ == "__main__":
   main()
