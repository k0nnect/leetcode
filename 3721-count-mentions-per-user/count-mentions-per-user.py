class Solution(object):
    def countMentions(self, numberOfUsers, events):
        for e in events:
            e[1] = int(e[1])
        events.sort(key=lambda x: (x[1], 0 if x[0] == "OFFLINE" else 1))

        mentions = [0] * numberOfUsers
        offline_until = [None] * numberOfUsers

        def update_online(current_time):
            for i in range(numberOfUsers):
                if offline_until[i] is not None and offline_until[i] <= current_time:
                    offline_until[i] = None

        for event in events:
            etype, timestamp, data = event
            update_online(timestamp)
            if etype == "OFFLINE":
                uid = int(data)
                offline_until[uid] = timestamp + 60
            else:
                tokens = data.split()
                if "ALL" in tokens:
                    for i in range(numberOfUsers):
                        mentions[i] += 1
                elif "HERE" in tokens:
                    for i in range(numberOfUsers):
                        if offline_until[i] is None:
                            mentions[i] += 1
                else:
                    for token in tokens:
                        if token.startswith("id"):
                            uid = int(token[2:])
                            mentions[uid] += 1

        return mentions