import os
import smtplib
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import cv2

import nexmo
from pprint import pprint

#Capture image
def capture_image():
    print('Capturing Image')
    camera =  cv2.VideoCapture(0)
    ret, frame = camera.read()
    fheight = frame.shape[0]/2
    fwidth = frame.shape[1]/2
    cv2.imshow("Captured Image", frame)
    if cv2.waitKey(1) & 0XFF == ord('q'):
        frame = cv2.resize(frame,(fwidth, fheight))
        cv2.imwrite('image.png',frame)
        cv2.destroyAllWindows()
    return 'image.png'

#Record Video
def record_video():
    print('recording video')
    camera = cv2.VideoCapture(0)
    # Define the codec and create VideoWriter object
    (grabbed, frame) = camera.read()
    fheight = frame.shape[0]
    fwidth = frame.shape[1]
    print(fwidth, fheight)
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter('output.avi', fourcc, 20.0, (fwidth, fheight))

    while camera.isOpened():
        ret, frame = camera.read()
        if ret:
            frame= cv2.flip(frame, 1)
            out.write(frame)
            cv2.imshow('Live video', frame)
            if cv2.waitKey(1) == 13:
                break
        else:
            break

    camera.release()
    out.release()
    cv2.destroyAllWindows()
    return 'output.avi'

#Stream Video
def stream_video():
    print('streaming video')

#Send EMail
def send_email(emailAddress,message, attchmentPath=None):
    print(f'Sending email to {emailAddress}')
    s = smtplib.SMTP(host='smtp.gmail.com', port=587)
    s.starttls()
    s.login('username', 'password')

    #setup Message
    msg = MIMEMultipart()
    msg['From']='JoshuaTesting SmartEcho'
    msg['To'] = emailAddress
    msg['Subject'] = 'Intrusion detect by SmartECho'

    msg.attach(MIMEText(message, 'plain'))

#attach file
    if not attchmentPath==None:
        attachment = MIMEBase('application', "octet-stream")
        with open(attchmentPath, 'rb') as file:
            attachment.set_payload(file.read())
        encoders.encode_base64(attachment)
        attachment.add_header('Content-Disposition',
                        'attachment; filename="{}"'.format(os.path.basename(attchmentPath)))
        msg.attach(attachment)

    s.send_message(msg)

    del msg
    s.quit()
    print('Email sent!')

#Send Sms
def send_sms_call(phoneNumber):
    #I created a nexmo account for this... they bill about 0.03 euros for this
    #send Sms
    print(f'Sending Message to {phoneNumber}')
    client = nexmo.Client(key='9ce96023', secret='NyQM7jRyIDQxCAbr')
    response = client.send_message({
                'from': 'SmartECho',
                'to': phoneNumber,
                'text': 'Intrusion detected at your home',
            })
    print(response)
    #call phone
    client = nexmo.Client(
      application_id='60a921b5-a492-4f1b-b895-c30bbdf272e6',
      private_key='private.key',
    )
    ncco = [
      {
        'action': 'talk',
        'voiceName': 'Joey',
        'text': 'Hello, there is an intrusion in your home, you need to act fast!'
      }
    ]
    response = client.create_call({
      'to': [{
        'type': 'phone',
        'number': phoneNumber
      }],
      'from': {
        'type': 'phone',
        'number': '2348138596607'
      },
      'ncco': ncco
    })
    pprint(response)


if __name__ == '__main__':
    send_email("jj.john0123@gmail.com","Message from SmartECho", 'image.png')
    #record_video()