# Build dPay's Jackson Test Network From Source

## Docker
### Build the image from source with docker

Docker isn't just for downloading already built images, it can be used to build from source the same way you would otherwise build. By doing this you ensure that your build environment is identical to what we use to develop the software. Use the below command to start the build:

```
docker build -t=dpay/franklin .
```

Don't forget the `.` at the end of the line which indicates the build target is in the current directory.

This will build everything including running our full suite of tests during the build process. It will anywhere from thirty minutes to a couple hours depending on how fast your equipment is.

When the build completes you will see a message indicating that it is 'successfully built'.
