import requests
class MyClass(GeneratedClass):
    def __init__(self):
        GeneratedClass.__init__(self)

    def onLoad(self):
        #put initialization code here
        pass

    def onUnload(self):
        #put clean-up code here
        pass

    def onInput_onStart(self):
        #self.onStopped() #activate the output of the box
        url="http://api.openweathermap.org/data/2.5/weather?q=kansas,us&mode=json&units=metric&APPID=c13804bd024d1d6fa4ab4c0d10f4cd02"
        response=requests.request("POST", url)
        data=response.json()
        result=data['weather'][0]['description']
        tts=ALProxy("ALTextToSpeech")
        tts.say(str(result))

    def onInput_onStop(self):
        self.onUnload() #it is recommended to reuse the clean-up as the box is stopped
        self.onStopped() #activate the output of the box
