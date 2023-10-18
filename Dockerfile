# Use an official Python runtime as the parent image
FROM python:3.8-slim-buster

# Set the working directory in the container
WORKDIR /app

# Install essential packages and libraries
RUN apt-get update && apt-get install -y build-essential libopencv-dev python3-opencv pkg-config

# Copy the current directory contents into the container at /app
COPY . /app

# Make sure the setup script is executable and run it
RUN chmod +x ./setup.sh && ./setup.sh

RUN chmod -R 777 /app/src/py/static/images

# Expose port 5000
EXPOSE 5000

# Run main.py when the container launches
CMD ["python3", "src/py/main.py"]
