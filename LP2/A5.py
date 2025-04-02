travel_info = {
    "Destinations": {
        "Beach": "Popular beach destinations include Goa, Maldives, Bali, Phuket, Seychelles, Santorini, Fiji, Hawaii, and Dubai.",
        "Mountain": "Great mountain destinations are Manali, Shimla, Ooty, Darjeeling, Leh-Ladakh, Sikkim, the Swiss Alps, Mount Everest Base Camp, and Banff.",
        "Historical": "Famous historical places include Rome, Athens, Agra, Cairo, Petra, Jerusalem, Machu Picchu, Angkor Wat, and the Giza Pyramids.",
        "Europe": "Popular European tourist destinations include London, Paris, Barcelona, Madrid, Zurich, Amsterdam, Venice, Rome, and Edinburgh.",
        "Asia": "Popular Asian tourist destinations are Goa, Andaman and Nicobar Islands, Tokyo, Bali, Phuket, Hampi, Kyoto, Singapore, and Dubai.",
        "North America": "Popular tourist destinations in North America include New York, San Francisco, Cancun, Chichen Itza, Baja California, Niagara Falls, Los Angeles, and Vancouver.",
        "South America": "Popular tourist destinations in South America include Patagonia, Rio de Janeiro, Santiago, Buenos Aires, Machu Picchu, the Galapagos Islands, and Lima.",
        "Africa": "Popular African tourist destinations include Cape Town, Marrakech, Cairo, Serengeti National Park, Victoria Falls, Zanzibar, and Nairobi.",
        "Australia": "Top Australian tourist destinations include Sydney, Melbourne, the Great Barrier Reef, Tasmania, Uluru, Gold Coast, and Brisbane."
    },

    "Ticket": {
        "Flight": "For flight booking, visit https://www.makemytrip.com/flights/, https://www.kayak.com/, or https://www.skyscanner.net/.",
        "Train": "For train bookings, visit https://www.irctc.co.in/ or https://www.rome2rio.com/ for international options.",
        "Bus": "For bus bookings, visit https://www.redbus.in/ or https://www.busbud.com/.",
        "Cruise": "For cruises, visit https://www.cruisecritic.com/ or https://www.carnival.com/."
    },

    "Hotel": {
        "General": "For hotel reservations, visit https://www.booking.com/ or https://www.agoda.com/.",
        "Luxury": "For luxury hotels, visit https://www.lhw.com/ or https://www.fourseasons.com/.",
        "Budget": "For budget options, visit https://www.hostelworld.com/ or https://www.airbnb.com/."
    },

    "Transport": {
        "Car Rental": "For car rentals, visit https://www.zoomcar.com/ or https://www.hertz.com/.",
        "Public Transport": "Most cities offer metros, buses, and taxis; apps like Uber or Lyft can be used.",
        "Taxi": "For taxis, use Uber, Lyft, or Ola.",
        "Bike Rental": "For bike rentals, visit https://www.bikeshare.com/ or https://www.spin.app/."
    },

    "Sightseeing": {
        "London": "Big Ben, Tower of London, Buckingham Palace, London Eye, British Museum, Hyde Park.",
        "Paris": "Eiffel Tower, Louvre Museum, Notre-Dame Cathedral, Sacré-Cœur, Champs-Élysées, Musée d'Orsay.",
        "Rome": "Colosseum, Roman Forum, Pantheon, Vatican City, Trevi Fountain, Piazza Navona.",
        "Tokyo": "Tokyo Tower, Meiji Shrine, Senso-ji Temple, Shibuya Crossing, Tokyo Disneyland, Ueno Park.",
        "New York": "Statue of Liberty, Central Park, Times Square, Empire State Building, Broadway.",
        "Sydney": "Sydney Opera House, Bondi Beach, Sydney Harbour Bridge, Darling Harbour, The Rocks.",
        "Dubai": "Burj Khalifa, Dubai Mall, Palm Jumeirah, Desert Safari, Dubai Marina, Dubai Fountain.",
        "Machu Picchu": "Inca Trail, Salkantay Trek, Lares Trek, Machu Picchu Mountain.",
        "Cape Town": "Table Mountain, Robben Island, V&A Waterfront, Kirstenbosch Gardens, Cape of Good Hope.",
        "Santorini": "Oia, Fira, Red Beach, Akrotiri Archaeological Site, Ancient Thira."
    },

    "Currency": {
        "London": "British Pound (GBP)",
        "Paris": "Euro (EUR)",
        "Tokyo": "Japanese Yen (JPY)",
        "New York": "US Dollar (USD)",
        "Sydney": "Australian Dollar (AUD)",
        "Dubai": "Emirati Dirham (AED)",
        "Machu Picchu": "Peruvian Nuevo Sol (PEN)"
    },

    "Weather": {
        "London": "Temperate maritime climate with mild year-round temperatures and occasional rain.",
        "Paris": "Temperate climate with mild winters (~5°C) and warm summers (~25°C).",
        "Tokyo": "Humid subtropical climate, hot summers (30°C+) and mild winters.",
        "New York": "Continental climate, cold winters (0°C to -5°C), hot summers (25°C to 30°C).",
        "Sydney": "Temperate climate with warm summers (~25°C) and mild winters (~12°C).",
        "Dubai": "Hot desert climate with extremely hot summers (up to 45°C) and mild winters.",
        "Machu Picchu": "Subtropical highland climate with mild days, cooler nights, and a rainy season from November to March."
    }
}

last_place = ""  # Stores last mentioned place for follow-up queries

def search(query, data):
    global last_place
    query = query.lower()

    # Check for follow-up queries
    if "there" in query or "that place" in query:
        if last_place:
            query = last_place.lower() + " " + query
        else:
            print("Please mention a place first.")
            return

    # Extract place and category from the query
    place = None
    category = None

    # Check for place
    for p in data["Sightseeing"]:
        if p.lower() in query:
            place = p
            last_place = p
            break

    # If no place is found, use the last_place
    if not place and last_place:
        place = last_place

    # Check for category
    if "currency" in query:
        category = "Currency"
    elif "weather" in query:
        category = "Weather"
    elif "sightseeing" in query or "places to visit" in query or "attractions" in query:
        category = "Sightseeing"
    elif "hotel" in query or "stay" in query:
        category = "Hotel"
    elif "flight" in query or "train" in query or "bus" in query or "cruise" in query:
        category = "Ticket"
    elif "transport" in query or "car rental" in query or "taxi" in query or "bike rental" in query:
        category = "Transport"
    elif "destination" in query or "beach" in query or "mountain" in query or "historical" in query:
        category = "Destinations"

    # Handle general category queries (e.g., "What are popular beach destinations?")
    if not place and category == "Destinations":
        if "beach" in query:
            print("Here are some popular beach destinations:")
            print(data["Destinations"]["Beach"])
        elif "mountain" in query:
            print("Here are some great mountain destinations:")
            print(data["Destinations"]["Mountain"])
        elif "historical" in query:
            print("Here are some famous historical places:")
            print(data["Destinations"]["Historical"])
        elif "europe" in query:
            print("Here are some popular European destinations:")
            print(data["Destinations"]["Europe"])
        elif "asia" in query:
            print("Here are some popular Asian destinations:")
            print(data["Destinations"]["Asia"])
        elif "north america" in query:
            print("Here are some popular North American destinations:")
            print(data["Destinations"]["North America"])
        elif "south america" in query:
            print("Here are some popular South American destinations:")
            print(data["Destinations"]["South America"])
        elif "africa" in query:
            print("Here are some popular African destinations:")
            print(data["Destinations"]["Africa"])
        elif "australia" in query:
            print("Here are some popular Australian destinations:")
            print(data["Destinations"]["Australia"])
        else:
            print("Here are some popular destinations:")
            for key, value in data["Destinations"].items():
                print(f"{key}: {value}")
        print("-------------")
        return

    # Handle service-related queries (e.g., "What are the flight prices?")
    if not place and category == "Ticket":
        if "flight" in query:
            print("For flight booking, visit:")
            print(data["Ticket"]["Flight"])
        elif "train" in query:
            print("For train bookings, visit:")
            print(data["Ticket"]["Train"])
        elif "bus" in query:
            print("For bus bookings, visit:")
            print(data["Ticket"]["Bus"])
        elif "cruise" in query:
            print("For cruises, visit:")
            print(data["Ticket"]["Cruise"])
        else:
            print("Here are some ticket booking options:")
            for key, value in data["Ticket"].items():
                print(f"{key}: {value}")
        print("-------------")
    elif place and category=="Ticket":
        if "flight" in query:
            print(f"For flight booking in {place}, visit:")
            print(data["Ticket"]["Flight"])
        elif "train" in query:
            print(f"For train bookingsm in {place}, visit:")
            print(data["Ticket"]["Train"])
        elif "bus" in query:
            print(f"For bus bookings in {place}, visit:")
            print(data["Ticket"]["Bus"])
        elif "cruise" in query:
            print(f"For cruises in {place}, visit:")
            print(data["Ticket"]["Cruise"])
        else:
            print("Here are some ticket booking options:")
            for key, value in data["Ticket"].items():
                print(f"{key}: {value}")
        print("-------------")
        return

    # Handle hotel-related queries (e.g., "Where can I find budget hotels?")
    if not place or category == "Hotel":
        if place:
            if "luxury" in query:
                print(f"For luxury hotels in {place}, visit:")
                print(data["Hotel"]["Luxury"])
            elif "budget" in query:
                print(f"For budget hotels in {place}, visit:")
                print(data["Hotel"]["Budget"])
            else:
                print(f"For hotel reservations in {place}, visit:")
                print(data["Hotel"]["General"])
            print("-------------")
            return
        else:
            print("General Details of hotels")
            print(data["Hotel"]["Budget"])
            print(data["Hotel"]["Luxury"])
            print(data["Hotel"]["General"])
            print("-------------")
            return

    # Handle transport-related queries (e.g., "Where can I rent a car?")
    if category == "Transport":
        if place:
            print(f"Here are some transport options for {place}:")
            print("For car rentals, visit [ZoomCar](https://www.zoomcar.com/) or [Hertz](https://www.hertz.com/)")
            print("For taxis, use Uber, Lyft, or Ola.")
            print("For bike rentals, visit [BikeShare](https://www.bikeshare.com/) or [Spin](https://www.spin.app/)")
            print("For public transport, most cities offer metros, buses, and taxis; apps like Uber or Lyft can be used.")
        else:
            print("Here are some general transport options:")
            print("For car rentals, visit [ZoomCar](https://www.zoomcar.com/) or [Hertz](https://www.hertz.com/)")
            print("For taxis, use Uber, Lyft, or Ola.")
            print("For bike rentals, visit [BikeShare](https://www.bikeshare.com/) or [Spin](https://www.spin.app/)")
            print("For public transport, most cities offer metros, buses, and taxis; apps like Uber or Lyft can be used.")
        print("-------------")
        return

    # Handle specific place queries
    if not category:
        if place:
            print(f"Here are the general details for {place}:")
            print(data["Sightseeing"][place])
            print(data["Weather"][place])
            print(data["Currency"][place])
            print("-------------")
        else:
            print("Sorry, I couldn't understand your query. Please try again.")
        return

    # Provide specific information based on category
    if category in data:
        if place and place in data[category]:
            print(f"Here are the {category.lower()} details for {place}:")
            print(data[category][place])
            print("-------------")
        else:
            print(f"Sorry, I don't have {category.lower()} information for {place}.")
    else:
        print(f"Sorry, I don't have information for the category '{category}'.")


while True:
    choice = input("Would you like to ask a query? (Y for yes / N for no): ").lower()
    if choice == 'y':
        user_query = input("Please enter your travel query: ")
        search(user_query, travel_info)
    else:
        print("Thank you for using the travel chatbot!")
        break
