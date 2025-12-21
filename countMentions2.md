import java.util.*;

class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        // group incoming events by timestamp (ascending)
        TreeMap<Integer, List<List<String>>> timeBuckets = new TreeMap<>();
        for (List<String> ev : events) {
            int t = Integer.parseInt(ev.get(1));
            timeBuckets.computeIfAbsent(t, k -> new ArrayList<>()).add(ev);
        }

        int[] result = new int[numberOfUsers];
        boolean[] online = new boolean[numberOfUsers];
        int[] blockedUntil = new int[numberOfUsers];
        Arrays.fill(online, true); // everyone starts online

        for (Map.Entry<Integer, List<List<String>>> entry : timeBuckets.entrySet()) {
            int now = entry.getKey();
            List<List<String>> batch = entry.getValue();

            // first: reactivate users whose offline period expired at or before `now`
            for (int u = 0; u < numberOfUsers; u++) {
                if (!online[u] && blockedUntil[u] <= now) {
                    online[u] = true;
                    blockedUntil[u] = 0;
                }
            }

            // apply OFFLINE events (they take effect immediately in this time slot)
            for (List<String> ev : batch) {
                if ("OFFLINE".equals(ev.get(0))) {
                    int id = Integer.parseInt(ev.get(2));
                    if (id >= 0 && id < numberOfUsers) {
                        online[id] = false;
                        blockedUntil[id] = now + 60; // offline for next 60 seconds
                    }
                }
            }

            // handle MESSAGE events and count mentions
            for (List<String> ev : batch) {
                if (!"MESSAGE".equals(ev.get(0))) continue;

                String mentionText = ev.get(2);
                if (mentionText == null || mentionText.isEmpty()) continue;

                String[] tokens = mentionText.split("\\s+");
                for (String tok : tokens) {
                    if ("ALL".equals(tok)) {
                        for (int u = 0; u < numberOfUsers; u++) result[u]++;
                    } else if ("HERE".equals(tok)) {
                        for (int u = 0; u < numberOfUsers; u++) {
                            if (online[u]) result[u]++;
                        }
                    } else if (tok.startsWith("id")) {
                        try {
                            int id = Integer.parseInt(tok.substring(2));
                            if (id >= 0 && id < numberOfUsers) result[id]++;
                        } catch (NumberFormatException ignore) { }
                    }
                }
            }
        }

        return result;
    }
}
