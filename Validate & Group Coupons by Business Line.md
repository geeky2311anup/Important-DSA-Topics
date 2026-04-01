import java.util.*;

class Solution {
    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        List<String> result = new ArrayList<>();

        /*
            Create separate buckets for each valid business category.
            We will later sort each bucket and merge in required order.
        */
        List<String> elec = new ArrayList<>();
        List<String> groc = new ArrayList<>();
        List<String> pharm = new ArrayList<>();
        List<String> rest = new ArrayList<>();

        int n = code.length;

        for (int i = 0; i < n; i++) {

            // Step 1: Skip inactive coupons immediately
            if (!isActive[i]) continue;

            String line = businessLine[i];

            /*
                Step 2: Validate business category
                Only allow these 4 types, ignore all others
            */
            if (!(line.equals("electronics") ||
                  line.equals("grocery") ||
                  line.equals("pharmacy") ||
                  line.equals("restaurant"))) {
                continue;
            }

            String c = code[i];

            // Step 3: Skip null or empty coupon codes
            if (c == null || c.isEmpty()) continue;

            /*
                Step 4: Validate coupon string
                Allowed characters:
                - Alphabets (A-Z, a-z)
                - Digits (0-9)
                - Underscore (_)
                If any invalid character appears → discard
            */
            boolean valid = true;
            for (char ch : c.toCharArray()) {
                if (!(Character.isLetterOrDigit(ch) || ch == '_')) {
                    valid = false;
                    break;
                }
            }

            if (!valid) continue;

            /*
                Step 5: Place coupon into correct category bucket
                We use first character of businessLine for quick mapping
            */
            char start = line.charAt(0);

            if (start == 'e') elec.add(c);       // electronics
            else if (start == 'g') groc.add(c);  // grocery
            else if (start == 'p') pharm.add(c); // pharmacy
            else if (start == 'r') rest.add(c);  // restaurant
        }

        /*
            Step 6: Sort each category individually (lexicographically)
        */
        Collections.sort(elec);
        Collections.sort(groc);
        Collections.sort(pharm);
        Collections.sort(rest);

        /*
            Step 7: Merge results in fixed priority order:
            electronics → grocery → pharmacy → restaurant
        */
        result.addAll(elec);
        result.addAll(groc);
        result.addAll(pharm);
        result.addAll(rest);

        return result;
    }
}
