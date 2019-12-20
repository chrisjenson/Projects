# frozen_string_literal: true

json.extract! organization, :id, :email, :name, :phone_no, :address, :city, :state, :zip_code, :description, :approved, :created_at, :updated_at
json.url organization_url(organization, format: :json)
