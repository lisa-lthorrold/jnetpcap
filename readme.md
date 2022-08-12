### Read Me

- This project is to support the changes required in the Flow Meter tool https://github.com/GintsEngelen/CICFlowMeter
- The issue at hand is packets with TCP Segmentation offsets (i.e. length field in the IP header is set to 0). The issue causes flows to be generated with src/dst port = 0, since the jnetpcap library parses packets based on specified lengths within the header
- The initial commit is trunk from revision 1425 of the original jnetpcap project (https://sourceforge.net/projects/jnetpcap/) - this is the closest build to the one used in the Flowmeter to - so as to maintain original functionality as much as possible. Later revisions were investigated, but had issues with build/functionality
- GCC compiler 4.5.2 is required to build the c++ files in this project (in the ant build script)
- A build needs to be done separately on Windows and Linux machines to generate the correct libraries for the respective operating systems