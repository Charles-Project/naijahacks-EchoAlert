
import Pi3picam
import picamera
import svideo
from datetime import datetime
from subprocess import call
from time import sleep
from gpiozero import LED
from gpiozero import Buzzer
import io
import logging
import socketserver
from threading import Condition
from http import server
#import the class definition from "email_handler.py" file
from email_handler1 import Class_eMail#set the email ID where you want to send the test email 
To_Email_ID = "chukuedna8@gmail.com@yahoo.com"
led = LED(4)
bz=Buzzer(2)
bz.on()
led.off()


PAGE="""\
<html>
<head>
<title>Raspberry Pi - Surveillance Camera</title>
</head>
<body>
<center><h1>Raspberry Pi - Surveillance Camera</h1></center>
<center><img src="stream.mjpg" width="640" height="480"></center>
</body>
</html>
"""
class StreamingOutput(object):
    def __init__(self):
        self.frame = None
        self.buffer = io.BytesIO()
        self.condition = Condition()

    def write(self, buf):
        if buf.startswith(b'\xff\xd8'):
            # New frame, copy the existing buffer's content

     # clients it's available
            self.buffer.truncate()
            with self.condition:
                self.frame = self.buffer.getvalue()
                self.condition.notify_all()
            self.buffer.seek(0)
        return self.buffer.write(buf)

class StreamingHandler(server.BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == '/':
            self.send_response(301)
            self.send_header('Location', '/index.html')
            self.end_headers()
        elif self.path == '/index.html':
            content = PAGE.encode('utf-8')
            self.send_response(200)
            self.send_header('Content-Type', 'text/html')
            self.send_header('Content-Length', len(content))
            self.end_headers()
            self.wfile.write(content)
        elif self.path == '/stream.mjpg':
            self.send_response(200)
            self.send_header('Age', 0)
            self.send_header('Cache-Control', 'no-cache, private')
            self.send_header('Pragma', 'no-cache')
            self.send_header('Content-Type', 'multipart/x-mixed-replace; boundary=FRAME')
            self.end_headers()
            try:
                while True:
                    with output.condition:
                        output.condition.wait()
                        frame = output.frame
                    self.wfile.write(b'--FRAME\r\n')
                    self.send_header('Content-Type', 'image/jpeg')
                    self.send_header('Content-Length', len(frame))
                    self.end_headers()
                    self.wfile.write(frame)
                    self.wfile.write(b'\r\n')
            except Exception as e:
                logging.warning(
                    'Removed streaming client %s: %s',
                    self.client_address, str(e))
        else:
            self.send_error(404)
            self.end_headers()

class StreamingServer(socketserver.ThreadingMixIn, server.HTTPServer):
    allow_reuse_address = True
    daemon_threads = True


led.on()
sleep(1)
led.off()
sleep(1)
led.on()
sleep(1)
led.off()


motionstate = False
c = 0
v = True

while v:
    #motionstate = Pi3picam.motion()
    while c <= 3:
        motionstate = Pi3picam.motion()
        if  motionstate == False:
            c = 4
            motionstate = False
        c = c + 1
        
    print(motionstate)
    c = 0

    if (motionstate):
        with picamera.PiCamera() as camera:
            camera.start_preview()
            camera.resolution = (1280, 720)
            sleep(5)
            camera.capture('motionImage.jpg')
            camera.stop_preview()
            print ("picture taken")
            uche = 'motionImage.jpg'
            #mailformain.sendMail(uche)
            # Send Plain Text Email 
            email = Class_eMail()
            email.send_Text_Mail(To_Email_ID, 'Security Alert', 'Intruder Detected.')
            del email
            print("mail sent")
            v = False
            bz.off()
            sleep(2)
            bz.on()
            sleep(0.7)
            bz.off()
            sleep(2)
            bz.on()
            sleep(0.7)
            bz.off()
            sleep(2)
            bz.on()
            sleep(0.7)
            bz.off()
            sleep(2)
            bz.on()
            sleep(0.7)
            
            
            print("alarm off")

with picamera.PiCamera(resolution='640x480', framerate=24) as camera:
    output = StreamingOutput()
     #Uncomment the next line to change your Pi's Camera rotation (in degrees)
    #camera.rotation = 90
    camera.start_recording(output, format='mjpeg')
    try:
        address = ('', 8000)
        server = StreamingServer(address, StreamingHandler)
        server.serve_forever()
        sleep(5)
        v = True
        
    finally:
        camera.stop_recording()
                       
            

