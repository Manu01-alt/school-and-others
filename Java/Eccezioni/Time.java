    public class Time {
        public int hours;
        public int minutes;
        public int seconds;

        public Time(int hours, int minutes, int seconds) throws IllegalTimeException {
            if (!checkValidity(hours, minutes, seconds)) {
                throw new IllegalTimeException("Orario non valido");
            }
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        }


        public boolean checkValidity(int hours, int minutes, int seconds) {
            return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
        }


        class IllegalTimeException extends Exception { //creiamo una nostra eccezione
            public IllegalTimeException() {
                super();
            }

            public IllegalTimeException(String s) { 
                super(s);
            }
        }

        public static void main(String[] args) {
            try {
                Time t1 = new Time(25, 10, 30);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }   
        }


        
}
