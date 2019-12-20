# frozen_string_literal: true

# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rails db:seed command (or created alongside the database with db:setup).
#
# Examples:
#
#   movies = Movie.create([{ name: 'Star Wars' }, { name: 'Lord of the Rings' }])
#   Character.create(name: 'Luke', movie: movies.first)

# FIXME: only for dev modes
User.create!(email: 'admin@example.com', password: 'password', password_confirmation: 'password', admin: true)
student = User.create!(email: 'student@example.com', password: 'password', password_confirmation: 'password')
org_user = User.create!(email: 'organizer@example.com', password: 'password', password_confirmation: 'password')
new_org_user = User.create!(email: 'neworganizer@example.com', password: 'password', password_confirmation: 'password')

Organization.create!(user: org_user, name: 'example org', email: org_user.email, phone_no: '5453545354', address: "62 Road Street", city: "Ewing", state: "NJ", zip_code: "08890", description: "this is an org.", approved: true)
Organization.create!(user: new_org_user, name: 'example org', email: new_org_user.email, phone_no: '5453545354', address: "62 RoStreet", city: "Ewng", state: "NJ", zip_code: "08890", description: "this is a new org.")

Opportunity.create!(organization: org_user.organization, name: 'Event 2', address: '3 Street Road', city: 'Ewing', state: 'NJ', zip_code: '08650', transportation: true, description: 'an event', frequency: 'frequent', email: 'org@test.com', on_date: '2025-06-27', start_time: '04:22:00', end_time: '06:39:00', approved: true)
Opportunity.create!(organization: org_user.organization, name: 'Event 3', address: '3 Street Road', city: 'Ewing', state: 'NJ', zip_code: '08650', transportation: true, description: 'an event', frequency: 'frequent', email: 'org@test.com', on_date: '2025-07-16', start_time: '04:22:00', end_time: '06:07:00')
Opportunity.create!(organization: new_org_user.organization, name: 'Event 4', address: '3 Street Road', city: 'Ewing', state: 'NJ', zip_code: '08650', transportation: true, description: 'an event', frequency: 'frequent', email: 'org@test.com', on_date: '2025-08-22', start_time: '04:22:00', end_time: '06:07:00')
Opportunity.create!(organization: new_org_user.organization, name: 'Event 5', address: '3 Street Road', city: 'Ewing', state: 'NJ', zip_code: '08650', transportation: true, description: 'an event', frequency: 'frequent', email: 'org@test.com', on_date: '2025-09-19', start_time: '04:22', end_time: '06:07', approved: true)

Tag.create!(name: 'tag1', approved: true)
Tag.create!(name: 'tag2', approved: true)
Tag.create!(name: 'tag3', approved: true)
Tag.create!(name: 'tag4', approved: true)
Tag.create!(name: 'tag5', approved: true)
Tag.create!(name: 'tag6', approved: true)
Tag.create!(name: 'tag7', approved: true)
Tag.create!(name: 'tag8', approved: true)
Tag.create!(name: 'tag9', approved: true)
