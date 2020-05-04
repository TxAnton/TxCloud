import requests
import vk_api
import time
import datetime

from vk_api.longpoll import VkLongPoll, VkEventType
import random

random.random()

def get_random_id():
    return random.getrandbits(31) * random.choice([-1, 1])


def write_msg(user_id, message):
    vk.method('messages.send', {'user_id': user_id, 'message': message, "random_id":random.random()})

token = "09f03c581ee7842dc52bebc4ec75384755493593c7cfd77382323aa0b778a3d03ff9862bce220dcd8d129"
token = "c0efdfe27ea6de0c71033d33e3dfb109072b50ace73de5ff0a6aa53a3cc7689cd140a8908f3adb19416f5"
token = "e04276879eba920306792cb60ec9b39c670dbfae70eaf051ee4560e81b1266ef94dd5b6f228b245d1115d"
login, password = '87089089552',''

# Авторизуемся как сообщество
#vk_session = vk_api.VkApi(login=login,token=token)
#vk_session = vk_api.VkApi(login=login,token=token)
vk_session = vk_api.VkApi(token=token)
#vk_session = vk_api.VkApi(login, password)
#vk_session.auth(token_only=True)
'''
try:
    vk_session.auth()
except vk_api.AuthError as error_msg:
    print(error_msg)
    exit(0)
'''
#longpoll = VkLongPoll(vk_session)
vk = vk_session.get_api()

#file = open('echo.txt',"a")



#response = vk.status.get(user_id = 587950896)
#response = vk.wall.get(count=1)
#response = vk.users.get(user_ids = 587950896, fields = 'online')
#id = '215653646'
id = 'id215653646'
flag = 2

vk.messages.send(user_id="587950896", random_id=get_random_id(), message="Notifier start for " + id, group_id="193348765")

while(1):
    try:
        response = vk.users.get(user_ids=id, fields='online')



        c = int(response[0]['online'])

        if(c!=flag):
            msg = "User: \"" + id + "\" is " + ("Online" if c else "Offline") + " at " + str(datetime.datetime.now())
            vk.messages.send(user_id="587950896", random_id=get_random_id(), message=msg, group_id="193348765")

            file = open('echo.txt', "a")
            print(c,file=file)
            print(datetime.datetime.now(),file=file)
            print(c)
            print(datetime.datetime.now())
            file.close()
        flag = c
    except:
        if(flag != 4):
            flag = 4
            print('!')
        #vk_session = vk_api.VkApi(token=token
        vk = vk_session.get_api()

    time.sleep(5)


#print(response[0]['online'])


print(response)
'''
for event in longpoll.listen():

        if event.type == VkEventType.MESSAGE_NEW:
            print('Новое сообщение:')

            if event.from_me:
                print('От меня для: ', end='')
            elif event.to_me:
                print('Для меня от: ', end='')

            if event.from_user:
                print(event.user_id)
            elif event.from_chat:
                print(event.user_id, 'в беседе', event.chat_id)
            elif event.from_group:
                print('группы', event.group_id)

            print('Текст: ', event.text)
            print()

        elif event.type == VkEventType.USER_TYPING:
            print('Печатает ', end='')

            if event.from_user:
                print(event.user_id)
            elif event.from_group:
                print('администратор группы', event.group_id)

        elif event.type == VkEventType.USER_TYPING_IN_CHAT:
            print('Печатает ', event.user_id, 'в беседе', event.chat_id)

        elif event.type == VkEventType.USER_ONLINE:
            print('Пользователь', event.user_id, 'онлайн', event.platform)

        elif event.type == VkEventType.USER_OFFLINE:
            print('Пользователь', event.user_id, 'оффлайн', event.offline_type)

        else:
            print(event.type, event.raw[1:])
'''