<<<<<<< HEAD

=======
Team Members

---

Charles Urutashe
Oyedele Tomilola
Richard Saseun
John Joshua

> > > > > > > c30928ec1aa9f62aa388348d6c0eca60fe1de564

## Proposed Solution

A smart security web system, that secures the user, by checking for intruder and alerting the user during security breach. The system uses a sensor to detects for intruders, and when an intruder is detected. It sends message and snapshot of the incident to the user via the user email address and display the video scene by streaming it on the web application.
two prototypes that support different technology are design and implemented.
Model 1:
Sense for intruder using infrared sensor, when an intruder is detected it sends sms to the user. The user can be a single or multiple persons. A keypad is use to enter in the number of users (recipients) to send message to. It sends the messgae with the required location.
Model 2:
Sense for intruder using the motion sensor and whe an intruder is detected it will alert the user, via sms and call, send snapshot of the incident to the user gmail account. Stream the video via a web server (raspberry pi as the web server) or via a facebook account.

## Proposed Stack

Bootstrap, Vuejs, embedded c, nexmo API and Python.

## Benefit

1. It creates an enabling a safe environment for the user.
2. it sends snapshot of the crime scene to the user, enabling the user or authorities to knpw what the incident is like.
3. It streams the video on the web server or facebook in real time, this makes the user to visualize, the incident.
4. the device is a good security system.

## Includes

```
Vue, Sass, Prettier, Vue-router, Vuexpersistedstate, NPM
```

> > > > > > > c30928ec1aa9f62aa388348d6c0eca60fe1de564

## Project setup

```
npm install
```

### Compiles and hot-reloads for development

```
npm run serve
```

<<<<<<< HEAD

### Compiles and minifies for production

```
npm run build
```

### Run your tests

```
npm run test
```

### Lints and fixes files

```
npm run lint
```

### Customize configuration

# See [Configuration Reference](https://cli.vuejs.org/config/).
